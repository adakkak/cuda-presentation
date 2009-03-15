// bumpmap.cpp
// OpenGL SuperBible, Chapter 17
// Demonstrates shader-based bump mapping
// Program by Benjamin Lipchak

#include "shared/gltools.h"   // OpenGL toolkit
#include "shared/glframe.h"   // OpenGL toolkit

#include <stdio.h>

#define BUMPMAP           0
#define SHOWBUMP          1
#define TOTAL_SHADER_SETS 2

#define BOX               0
#define CYLINDER          1
#define TORUS             2
#define TOTAL_SHAPES      3

#define RIVETS            0
#define PYRAMIDS          1
#define TOTAL_BUMPMAPS    2

GLuint fShader[TOTAL_SHADER_SETS]; // shader object names
GLuint vShader[TOTAL_SHADER_SETS]; 
GLuint progObj[TOTAL_SHADER_SETS]; 
GLboolean needsValidation[TOTAL_SHADER_SETS];
char *shaderNames[TOTAL_SHADER_SETS] = {"bumpmap", "showbump"};
char *shapeNames[TOTAL_SHAPES] = {"box", "cylinder", "torus"};
char *bumpmapNames[TOTAL_BUMPMAPS] = {"rivets", "pyramids"};

GLint whichShader = BUMPMAP;            // current shader
GLint whichShape = BOX;                 // current shape
GLint whichBumpmap = RIVETS;            // current bumpmap

GLint windowWidth = 512;                // window size
GLint windowHeight = 512;

GLint mainMenu, shapeMenu, shaderMenu, bumpmapMenu;

GLint maxTexSize;                       // maximum allowed size for 1D/2D texture

GLfloat cameraPos[] = { 0.0f, 125.0f, -200.0f, 1.0f};
GLfloat lightPos0[3];

GLfloat lightRotation = 90.0f;

#define MAX_INFO_LOG_SIZE 2048

// 2D raised rivets and divets
GLvoid CreateRivetMap()
{
    GLfloat texels[128 * 128 * 4];
    GLint texSize = (maxTexSize > 128) ? 128 : maxTexSize;
    GLfloat x, y, radius, nx, ny, nz, scale;
    GLint u, v;

    for (v = 0; v < texSize; v++)
    {
        y = ((GLfloat)v - (((GLfloat)texSize - 1.0f) * 0.5f)) / (((GLfloat)texSize - 1.0f) * 0.5f);

        for (u = 0; u < texSize; u++)
        {
            x = ((GLfloat)u - (((GLfloat)texSize - 1.0f) * 0.5f)) / (((GLfloat)texSize - 1.0f) * 0.5f);
            radius = (x*x) + (y*y);

            if (radius <= 0.64f)
            {
                nx = x * 1.25f;
                ny = y * 1.25f;
                nz = (GLfloat)sqrt(0.64 - radius) * 1.25f;
                scale = 1.0f / sqrt((nx*nx) + (ny*ny) + (nz*nz));

                texels[(v*texSize*4)+(u*4)+0] = (nx * scale * 0.5f) + 0.5f;
                texels[(v*texSize*4)+(u*4)+1] = (ny * scale * 0.5f) + 0.5f;
                texels[(v*texSize*4)+(u*4)+2] = (nz * scale * 0.5f) + 0.5f;
                texels[(v*texSize*4)+(u*4)+3] = 1.0f;
            }
            else
            {
                texels[(v*texSize*4)+(u*4)+0] = 0.0f;
                texels[(v*texSize*4)+(u*4)+1] = 0.0f;
                texels[(v*texSize*4)+(u*4)+2] = 1.0f;
                texels[(v*texSize*4)+(u*4)+3] = 1.0f;
            }
        }
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16, texSize, texSize, 0, GL_RGBA, GL_FLOAT, texels);
}

// 2D raised pyramids
GLvoid CreatePyramidMap()
{
    GLfloat texels[128 * 128 * 4];
    GLint texSize = (maxTexSize > 128) ? 128 : maxTexSize;
    GLfloat x, y, nx, ny, nz, scale;
    GLint u, v;

    for (v = 0; v < texSize; v++)
    {
        y = ((GLfloat)v - (((GLfloat)texSize - 1.0f) * 0.5f)) / (((GLfloat)texSize - 1.0f) * 0.5f);

        for (u = 0; u < texSize; u++)
        {
            x = ((GLfloat)u - (((GLfloat)texSize - 1.0f) * 0.5f)) / (((GLfloat)texSize - 1.0f) * 0.5f);

            if ((fabs(x)+fabs(y)) <= 0.8f)
            {
                if ((x >= 0) && (y >= 0))
                {
                    nx = 0.75f;
                    ny = 0.75f;
                }
                else if ((x < 0) && (y >= 0))
                {
                    nx = -0.75f;
                    ny = 0.75f;
                }
                else if ((x >= 0) && (y < 0))
                {
                    nx = 0.75f;
                    ny = -0.75f;
                }
                else
                {
                    nx = -0.75f;
                    ny = -0.75f;
                }
                nz = 1.0f;
                scale = 1.0f / sqrt((nx*nx) + (ny*ny) + (nz*nz));

                texels[(v*texSize*4)+(u*4)+0] = (nx * scale * 0.5f) + 0.5f;
                texels[(v*texSize*4)+(u*4)+1] = (ny * scale * 0.5f) + 0.5f;
                texels[(v*texSize*4)+(u*4)+2] = (nz * scale * 0.5f) + 0.5f;
                texels[(v*texSize*4)+(u*4)+3] = 1.0f;
            }
            else
            {
                texels[(v*texSize*4)+(u*4)+0] = 0.0f;
                texels[(v*texSize*4)+(u*4)+1] = 0.0f;
                texels[(v*texSize*4)+(u*4)+2] = 1.0f;
                texels[(v*texSize*4)+(u*4)+3] = 1.0f;
            }
        }
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16, texSize, texSize, 0, GL_RGBA, GL_FLOAT, texels);
}

// Load shader from disk into a null-terminated string
GLchar *LoadShaderText(const char *fileName)
{
    GLchar *shaderText = NULL;
    GLint shaderLength = 0;
    FILE *fp;

    fp = fopen(fileName, "r");
    if (fp != NULL)
    {
        while (fgetc(fp) != EOF)
        {
            shaderLength++;
        }
        rewind(fp);
        shaderText = (GLchar *)malloc(shaderLength+1);
        if (shaderText != NULL)
        {
            fread(shaderText, 1, shaderLength, fp);
        }
        shaderText[shaderLength] = '\0';
        fclose(fp);
    }

    return shaderText;
}

// Compile shaders
void PrepareShader(GLint shaderNum)
{
    char fullFileName[255];
    GLchar *shString;
    const GLchar *shStringPtr[1];
    GLint success;

    // Create shader objects and specify shader text
    sprintf(fullFileName, "./shaders/%s.vs", shaderNames[shaderNum]);
    shString = LoadShaderText(fullFileName);
    if (!shString)
    {
        fprintf(stderr, "Unable to load \"%s\"\n", fullFileName);
        Sleep(5000);
        exit(0);
    }
    vShader[shaderNum] = glCreateShader(GL_VERTEX_SHADER);
    shStringPtr[0] = shString;
    glShaderSource(vShader[shaderNum], 1, shStringPtr, NULL);
    free(shString);

    // Compile shaders and check for any errors
    glCompileShader(vShader[shaderNum]);
    glGetShaderiv(vShader[shaderNum], GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[MAX_INFO_LOG_SIZE];
        glGetShaderInfoLog(vShader[shaderNum], MAX_INFO_LOG_SIZE, NULL, infoLog);
        fprintf(stderr, "Error in vertex shader #%d compilation!\n", shaderNum);
        fprintf(stderr, "Info log: %s\n", infoLog);
        Sleep(10000);
        exit(0);
    }

    sprintf(fullFileName, "./shaders/%s.fs", shaderNames[shaderNum]);
    shString = LoadShaderText(fullFileName);
    if (!shString)
    {
        fprintf(stderr, "Unable to load \"%s\"\n", fullFileName);
        Sleep(5000);
        exit(0);
    }
    fShader[shaderNum] = glCreateShader(GL_FRAGMENT_SHADER);
    shStringPtr[0] = shString;
    glShaderSource(fShader[shaderNum], 1, shStringPtr, NULL);
    free(shString);

    // Compile shaders and check for any errors
    glCompileShader(fShader[shaderNum]);
    glGetShaderiv(fShader[shaderNum], GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[MAX_INFO_LOG_SIZE];
        glGetShaderInfoLog(fShader[shaderNum], MAX_INFO_LOG_SIZE, NULL, infoLog);
        fprintf(stderr, "Error in fragment shader #%d compilation!\n", shaderNum);
        fprintf(stderr, "Info log: %s\n", infoLog);
        Sleep(10000);
        exit(0);
    }

    // Create program object, attach shader, then link
    progObj[shaderNum] = glCreateProgram();
    glAttachShader(progObj[shaderNum], vShader[shaderNum]);
    glAttachShader(progObj[shaderNum], fShader[shaderNum]);

    glLinkProgram(progObj[shaderNum]);
    glGetProgramiv(progObj[shaderNum], GL_LINK_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[MAX_INFO_LOG_SIZE];
        glGetProgramInfoLog(progObj[shaderNum], MAX_INFO_LOG_SIZE, NULL, infoLog);
        fprintf(stderr, "Error in program #%d linkage!\n", shaderNum);
        fprintf(stderr, "Info log: %s\n", infoLog);
        Sleep(10000);
        exit(0);
    }

    // Program object has changed, so we should revalidate
    needsValidation[shaderNum] = GL_TRUE;
}

void DrawCylinder(GLfloat radius, GLfloat height, GLint slices, GLfloat xTexScale, GLfloat yTexScale)
{
    GLfloat angleInc = (2.0f * 3.14159265f) / (GLfloat)slices;
    GLint i;

    glBegin(GL_QUAD_STRIP);

    for (i = 0; i <= slices; i++)
    {
        glMultiTexCoord2f(GL_TEXTURE0, xTexScale * i / (GLfloat)slices, 0.0f);
        glMultiTexCoord3f(GL_TEXTURE1, cos((angleInc * i) + (3.14159265f * 0.5f)), 0.0f, sin((angleInc * i) + (3.14159265f * 0.5f)));  // tangent
        glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 1.0f, 0.0f);                           // binormal
        glMultiTexCoord3f(GL_TEXTURE3, cos(angleInc * i), 0.0f, sin(angleInc * i)); // normal
        glVertex3f(radius * cos(angleInc * i), -height*0.5f, radius * sin(angleInc * i));
        glMultiTexCoord2f(GL_TEXTURE0, xTexScale * i / (GLfloat)slices, yTexScale);
        glVertex3f(radius * cos(angleInc * i), height*0.5f, radius * sin(angleInc * i));
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
    glMultiTexCoord3f(GL_TEXTURE1, 1.0f, 0.0f, 0.0f); // tangent
    glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 0.0f, 1.0f); // binormal
    glMultiTexCoord3f(GL_TEXTURE3, 0.0f, 1.0f, 0.0f); // normal
    glVertex3f(0.0f, height*0.5f, 0.0f);

    for (i = 0; i <= slices; i++)
    {
        glMultiTexCoord2f(GL_TEXTURE0, xTexScale * cos(angleInc * i) * 0.159155f, 
                                       xTexScale * sin(angleInc * i) * 0.159155f);
        glVertex3f(radius * cos(angleInc * -i), height*0.5f, radius * sin(angleInc * -i));
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
    glMultiTexCoord3f(GL_TEXTURE1, -1.0f, 0.0f, 0.0f); // tangent
    glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 0.0f, -1.0f); // binormal
    glMultiTexCoord3f(GL_TEXTURE3, 0.0f, -1.0f, 0.0f); // normal
    glVertex3f(0.0f, -height*0.5f, 0.0f);

    for (i = 0; i <= slices; i++)
    {
        glMultiTexCoord2f(GL_TEXTURE0, xTexScale * cos(angleInc * i) * 0.159155f, 
                                       xTexScale * sin(angleInc * i) * 0.159155f);
        glVertex3f(radius * cos(angleInc * i), -height*0.5f, radius * sin(angleInc * i));
    }

    glEnd();
}

void DrawTorus(GLfloat innerRadius, GLfloat ringRadius, GLint rings, GLint slices, GLfloat xTexScale, GLfloat yTexScale)
{
    GLfloat sliceAngleInc = (2.0f * 3.14159265f) / (GLfloat)slices;
    GLfloat ringAngleInc = (2.0f * 3.14159265f) / (GLfloat)rings;
    GLint i, j;

    for (i = 0; i <= rings; i++)
    {
        glBegin(GL_QUAD_STRIP);

        for (j = 0; j <= slices; j++)
        {
            glMultiTexCoord2f(GL_TEXTURE0, xTexScale * (i+1) / (GLfloat)rings, yTexScale * j / (GLfloat)slices);
            glMultiTexCoord3f(GL_TEXTURE1, cos((ringAngleInc * (i+1)) + (3.14159265f * 0.5f)), 0.0f, sin((ringAngleInc * (i+1)) + (3.14159265f * 0.5f)));  // tangent
            glMultiTexCoord3f(GL_TEXTURE2, 0.0f, sin((sliceAngleInc * j) + (3.14159265f * 0.5f)), 0.0f);  // binormal
            glMultiTexCoord3f(GL_TEXTURE3, cos(ringAngleInc * (i+1)), sin(sliceAngleInc * j), sin(ringAngleInc * (i+1))); // normal
            glVertex3f((innerRadius + ringRadius + (ringRadius * cos(sliceAngleInc * j))) * cos(ringAngleInc * (i+1)), (ringRadius * sin(sliceAngleInc * j)), (innerRadius + ringRadius + (ringRadius * cos(sliceAngleInc * j))) * sin(ringAngleInc * (i+1)));
            glMultiTexCoord2f(GL_TEXTURE0, xTexScale * i / (GLfloat)rings, yTexScale * j / (GLfloat)slices);
            glMultiTexCoord3f(GL_TEXTURE1, cos((ringAngleInc * i) + (3.14159265f * 0.5f)), 0.0f, sin((ringAngleInc * i) + (3.14159265f * 0.5f)));  // tangent
            glMultiTexCoord3f(GL_TEXTURE2, 0.0f, sin((sliceAngleInc * j) + (3.14159265f * 0.5f)), 0.0f);  // binormal
            glMultiTexCoord3f(GL_TEXTURE3, cos(ringAngleInc * i), sin(sliceAngleInc * j), sin(ringAngleInc * i)); // normal
            glVertex3f((innerRadius + ringRadius + (ringRadius * cos(sliceAngleInc * j))) * cos(ringAngleInc * i), (ringRadius * sin(sliceAngleInc * j)), (innerRadius + ringRadius + (ringRadius * cos(sliceAngleInc * j))) * sin(ringAngleInc * i));
        }

        glEnd();
    }
}

void DrawBox(GLfloat size, GLfloat texScale)
{
    size *= 0.5f;

    glBegin(GL_QUADS);
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
        glMultiTexCoord3f(GL_TEXTURE1, 1.0f, 0.0f, 0.0f);  // tangent
        glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 1.0f, 0.0f);  // binormal
        glMultiTexCoord3f(GL_TEXTURE3, 0.0f, 0.0f, -1.0f); // normal
        glVertex3f(-size, -size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, texScale);
        glVertex3f(-size, size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, texScale);
        glVertex3f(size, size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, 0.0f);
        glVertex3f(size, -size, -size);

        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
        glMultiTexCoord3f(GL_TEXTURE1, -1.0f, 0.0f, 0.0f);// tangent
        glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 1.0f, 0.0f); // binormal
        glMultiTexCoord3f(GL_TEXTURE3, 0.0f, 0.0f, 1.0f); // normal
        glVertex3f(size, -size, size);
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, texScale);
        glVertex3f(size, size, size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, texScale);
        glVertex3f(-size, size, size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, 0.0f);
        glVertex3f(-size, -size, size);

        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
        glMultiTexCoord3f(GL_TEXTURE1, 0.0f, 0.0f, 1.0f); // tangent
        glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 1.0f, 0.0f); // binormal
        glMultiTexCoord3f(GL_TEXTURE3, 1.0f, 0.0f, 0.0f); // normal
        glVertex3f(size, -size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, texScale);
        glVertex3f(size, size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, texScale);
        glVertex3f(size, size, size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, 0.0f);
        glVertex3f(size, -size, size);

        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
        glMultiTexCoord3f(GL_TEXTURE1, 0.0f, 0.0f, -1.0f); // tangent
        glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 1.0f, 0.0f);  // binormal
        glMultiTexCoord3f(GL_TEXTURE3, -1.0f, 0.0f, 0.0f); // normal
        glVertex3f(-size, -size, size);
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, texScale);
        glVertex3f(-size, size, size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, texScale);
        glVertex3f(-size, size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, 0.0f);
        glVertex3f(-size, -size, -size);

        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
        glMultiTexCoord3f(GL_TEXTURE1, 1.0f, 0.0f, 0.0f); // tangent
        glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 0.0f, 1.0f); // binormal
        glMultiTexCoord3f(GL_TEXTURE3, 0.0f, 1.0f, 0.0f); // normal
        glVertex3f(-size, size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, texScale);
        glVertex3f(-size, size, size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, texScale);
        glVertex3f(size, size, size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, 0.0f);
        glVertex3f(size, size, -size);

        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, 0.0f);
        glMultiTexCoord3f(GL_TEXTURE1, 1.0f, 0.0f, 0.0f);  // tangent
        glMultiTexCoord3f(GL_TEXTURE2, 0.0f, 0.0f, -1.0f); // binormal
        glMultiTexCoord3f(GL_TEXTURE3, 0.0f, -1.0f, 0.0f); // normal
        glVertex3f(-size, -size, size);
        glMultiTexCoord2f(GL_TEXTURE0, 0.0f, texScale);
        glVertex3f(-size, -size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, texScale);
        glVertex3f(size, -size, -size);
        glMultiTexCoord2f(GL_TEXTURE0, texScale, 0.0f);
        glVertex3f(size, -size, size);
    glEnd();
}

// Called to draw scene objects
void DrawModels(void)
{
    GLint uniformLoc = glGetUniformLocation(progObj[whichShader], "sampler0");
    if (uniformLoc != -1)
    {
        glUniform1i(uniformLoc, 0);
    }
    uniformLoc = glGetUniformLocation(progObj[whichShader], "lightPos0");
    if (uniformLoc != -1)
    {
        glUniform3fv(uniformLoc, 1, lightPos0);
    }

    // Draw box to demonstrate low-geometry, high-detail
    glColor3f(0.8f, 0.5f, 0.3f);
    switch (whichShape)
    {
    case CYLINDER:
        DrawCylinder(25.0f, 70.0f, 25, 20.0f, 10.0f);
        break;
    case TORUS:
        DrawTorus(20.0f, 15.0f, 50, 25, 40.0f, 12.0f);
        break;
    default:
        DrawBox(70.0f, 10.0f);
        break;
    }
}

// Called to draw scene
void RenderScene(void)
{
    // Track camera angle
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 
              0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Validate our shader before first use
    if (needsValidation[whichShader])
    {
        GLint success;

        glValidateProgram(progObj[whichShader]);
        glGetProgramiv(progObj[whichShader], GL_VALIDATE_STATUS, &success);
        if (!success)
        {
            GLchar infoLog[MAX_INFO_LOG_SIZE];
            glGetProgramInfoLog(progObj[whichShader], MAX_INFO_LOG_SIZE, NULL, infoLog);
            fprintf(stderr, "Error in program #%d validation!\n", whichShader);
            fprintf(stderr, "Info log: %s\n", infoLog);
            Sleep(10000);
            exit(0);
        }

        needsValidation[whichShader] = GL_FALSE;
    }
    
    // Draw objects in the scene
    DrawModels();
    
    if (glGetError() != GL_NO_ERROR)
        fprintf(stderr, "GL Error!\n");

    // Flush drawing commands
    glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
    GLint i;

    fprintf(stdout, "Bump Mapping Demo\n\n");

    // Make sure required functionality is available!
    if (!GLEE_VERSION_2_0 && (!GLEE_ARB_fragment_shader || 
                              !GLEE_ARB_vertex_shader || 
                              !GLEE_ARB_shader_objects || 
                              !GLEE_ARB_shading_language_100))
    {
        fprintf(stderr, "GLSL extensions not available!\n");
        Sleep(2000);
        exit(0);
    }

    // Make sure we have multitexture!
    if (!GLEE_VERSION_1_3 && !GLEE_ARB_multitexture)
    {
        fprintf(stderr, "Neither OpenGL 1.3 nor necessary"
                        " extensions are available!\n");
        Sleep(2000);
        exit(0);
    }

    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTexSize);

    fprintf(stdout, "Controls:\n");
    fprintf(stdout, "\tRight-click for menu\n\n");
    fprintf(stdout, "\tR/L arrows\t+/- rotate lights\n\n");
    fprintf(stdout, "\tx/X\t\tMove +/- in x direction\n");
    fprintf(stdout, "\ty/Y\t\tMove +/- in y direction\n");
    fprintf(stdout, "\tz/Z\t\tMove +/- in z direction\n\n");
    fprintf(stdout, "\tq\t\tExit demo\n\n");
    
    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

    // Misc. state
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);

    // Texture state
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
    CreateRivetMap();
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
    CreatePyramidMap();
    glBindTexture(GL_TEXTURE_2D, 0);

    lightPos0[0] = 300.0f * cos(-lightRotation * 3.14159265f / 180.0f);
    lightPos0[1] = 0.0f;
    lightPos0[2] = 300.0f * sin(-lightRotation * 3.14159265f / 180.0f);

    // Load and compile shaders
    for (i = 0; i < TOTAL_SHADER_SETS; i++)
    {
        PrepareShader(i);
    }

    // Install first shader
    glUseProgram(progObj[whichShader]);
}

void ProcessMenu(int value)
{
    if (value >= (TOTAL_SHAPES+TOTAL_SHADER_SETS+1))
    {
        char menuEntry[128];
        whichBumpmap = value - TOTAL_SHAPES - TOTAL_SHADER_SETS - 1;
        sprintf(menuEntry, "Choose bumpmap (currently \"%s\")", bumpmapNames[whichBumpmap]);
        glutSetMenu(mainMenu);
        glutChangeToSubMenu(3, menuEntry, bumpmapMenu);
        glBindTexture(GL_TEXTURE_2D, whichBumpmap);
    }
    else if (value >= (TOTAL_SHAPES+1))
    {
        char menuEntry[128];
        whichShader = value - TOTAL_SHAPES - 1;
        sprintf(menuEntry, "Choose shader (currently \"%s\")", shaderNames[whichShader]);
        glutSetMenu(mainMenu);
        glutChangeToSubMenu(2, menuEntry, shaderMenu);
        glUseProgram(progObj[whichShader]);
    }
    else
    {
        char menuEntry[128];
        whichShape = value - 1;
        sprintf(menuEntry, "Choose shape (currently \"%s\")", shapeNames[whichShape]);
        glutSetMenu(mainMenu);
        glutChangeToSubMenu(1, menuEntry, shapeMenu);
    }

    // Refresh the Window
    glutPostRedisplay();
}

void KeyPressFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'x':
        cameraPos[0] += 5.0f;
        break;
    case 'X':
         cameraPos[0] -= 5.0f;
        break;
    case 'y':
        cameraPos[1] += 5.0f;
        break;
    case 'Y':
        cameraPos[1] -= 5.0f;
        break;
    case 'z':
        cameraPos[2] += 5.0f;
        break;
    case 'Z':
        cameraPos[2] -= 5.0f;
        break;
    case 'q':
    case 'Q':
    case 27 : /* ESC */
        exit(0);
    }

    // Refresh the Window
    glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        lightRotation -= 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        lightRotation += 5.0f;
        break;
    case GLUT_KEY_UP:
        cameraPos[1] += 5.0f;
        break;
    case GLUT_KEY_DOWN:
        cameraPos[1] -= 5.0f;
        break;
    default:
        break;
    }

    lightPos0[0] = 300.0f * cos(-lightRotation * 3.14159265f / 180.0f);
    lightPos0[1] = 0.0f;
    lightPos0[2] = 300.0f * sin(-lightRotation * 3.14159265f / 180.0f);

    // Refresh the Window
    glutPostRedisplay();
}

void ChangeSize(int w, int h)
{
    windowWidth = w;
    windowHeight = h;
    glViewport(0, 0, windowWidth, windowHeight);
}

int main(int argc, char* argv[])
{
    GLint i;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Bump Mapping Demo");
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(KeyPressFunc);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);

    SetupRC();

    // Create the menus
    shapeMenu = glutCreateMenu(ProcessMenu);
    for (i = 0; i < TOTAL_SHAPES; i++)
    {
        char menuEntry[128];
        sprintf(menuEntry, "\"%s\"", shapeNames[i]);
        glutAddMenuEntry(menuEntry, 1+i);
    }

    shaderMenu = glutCreateMenu(ProcessMenu);
    for (i = 0; i < TOTAL_SHADER_SETS; i++)
    {
        char menuEntry[128];
        sprintf(menuEntry, "\"%s\"", shaderNames[i]);
        glutAddMenuEntry(menuEntry, 1+TOTAL_SHAPES+i);
    }

    bumpmapMenu = glutCreateMenu(ProcessMenu);
    for (i = 0; i < TOTAL_BUMPMAPS; i++)
    {
        char menuEntry[128];
        sprintf(menuEntry, "\"%s\"", bumpmapNames[i]);
        glutAddMenuEntry(menuEntry, 1+TOTAL_SHAPES+TOTAL_SHADER_SETS+i);
    }

    mainMenu = glutCreateMenu(ProcessMenu);
    {
        char menuEntry[128];
        sprintf(menuEntry, "Choose shape (currently \"%s\")", shapeNames[0]);
        glutAddSubMenu(menuEntry, shapeMenu);
        sprintf(menuEntry, "Choose shader (currently \"%s\")", shaderNames[0]);
        glutAddSubMenu(menuEntry, shaderMenu);
        sprintf(menuEntry, "Choose bumpmap (currently \"%s\")", bumpmapNames[0]);
        glutAddSubMenu(menuEntry, bumpmapMenu);
    }
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    if (glDeleteProgram && glDeleteShader)
    {
        for (i = 0; i < TOTAL_SHADER_SETS; i++)
        {
            glDeleteProgram(progObj[i]);
            glDeleteShader(vShader[i]);
            glDeleteShader(fShader[i]);
        }
    }

    return 0;
}
