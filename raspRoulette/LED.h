#ifndef _LED_H_
#define _LED_H_

class LED {
 private:
  bool _bInitOk;
  bool init();
  void select1(int x);
  void select2(int x);

 public:
  LED();
  ~LED();
  
  // turn on LED
  // i [i] index of LED (i=0, 1, ... 31)
  void on(int i);

  void test();
};

#endif
