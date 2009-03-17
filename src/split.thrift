namespace cpp split

const i16 PORT = 9853

service Split {

   binary display(),

   async void keyboardEventFunc(byte key, i16 x, i16 y ),

   async void mouseEventFunc(i16 button, i16 x, i16 y),

   async void mouseMotionFunc(i16 x, i16 y),

   async void reshapeFunc(i16 x, i16 y),

   async void idle()
}
