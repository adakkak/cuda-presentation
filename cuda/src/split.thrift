namespace cpp example

const i16 PORT = 9853

struct KeyboardEvent {
  1: byte ev,
  2: i16 x,
  3: i16 y
}

struct MouseEvent {
  1: i16 button,
  2: i16 state,
  3: i16 x,
  4: i16 y
}

struct MotionEvent {
  1: i16 x,
  2: i16 y
}

exception InvalidOperation {
  1: i32 what,
  2: string why
}

service Split {

   binary display(),

   async void keyboardEventFunc(1: KeyboardEvent e),

   async void mouseEventFunc(1: MouseEvent e),

   async void mouseMotionFunc(1: MotionEvent e),

   async void idle()
}
