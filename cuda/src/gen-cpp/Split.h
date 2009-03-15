/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef Split_H
#define Split_H

#include <TProcessor.h>
#include "split_types.h"

namespace split {

class SplitIf {
 public:
  virtual ~SplitIf() {}
  virtual void display(std::string& _return) = 0;
  virtual void keyboardEventFunc(const int8_t key, const int16_t x, const int16_t y) = 0;
  virtual void mouseEventFunc(const int16_t button, const int16_t x, const int16_t y) = 0;
  virtual void mouseMotionFunc(const int16_t x, const int16_t y) = 0;
  virtual void reshapeFunc(const int16_t x, const int16_t y) = 0;
  virtual void idle() = 0;
};

class SplitNull : virtual public SplitIf {
 public:
  virtual ~SplitNull() {}
  void display(std::string& /* _return */) {
    return;
  }
  void keyboardEventFunc(const int8_t /* key */, const int16_t /* x */, const int16_t /* y */) {
    return;
  }
  void mouseEventFunc(const int16_t /* button */, const int16_t /* x */, const int16_t /* y */) {
    return;
  }
  void mouseMotionFunc(const int16_t /* x */, const int16_t /* y */) {
    return;
  }
  void reshapeFunc(const int16_t /* x */, const int16_t /* y */) {
    return;
  }
  void idle() {
    return;
  }
};

class Split_display_args {
 public:

  Split_display_args() {
  }

  virtual ~Split_display_args() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;


  bool operator == (const Split_display_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Split_display_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Split_display_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_display_pargs {
 public:


  virtual ~Split_display_pargs() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;


  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_display_result {
 public:

  Split_display_result() : success("") {
  }

  virtual ~Split_display_result() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  std::string success;

  struct __isset {
    __isset() : success(false) {}
    bool success;
  } __isset;

  bool operator == (const Split_display_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Split_display_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Split_display_result & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_display_presult {
 public:


  virtual ~Split_display_presult() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  std::string* success;

  struct __isset {
    __isset() : success(false) {}
    bool success;
  } __isset;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);

};

class Split_keyboardEventFunc_args {
 public:

  Split_keyboardEventFunc_args() : key(0), x(0), y(0) {
  }

  virtual ~Split_keyboardEventFunc_args() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  int8_t key;
  int16_t x;
  int16_t y;

  struct __isset {
    __isset() : key(false), x(false), y(false) {}
    bool key;
    bool x;
    bool y;
  } __isset;

  bool operator == (const Split_keyboardEventFunc_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(x == rhs.x))
      return false;
    if (!(y == rhs.y))
      return false;
    return true;
  }
  bool operator != (const Split_keyboardEventFunc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Split_keyboardEventFunc_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_keyboardEventFunc_pargs {
 public:


  virtual ~Split_keyboardEventFunc_pargs() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  const int8_t* key;
  const int16_t* x;
  const int16_t* y;

  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_mouseEventFunc_args {
 public:

  Split_mouseEventFunc_args() : button(0), x(0), y(0) {
  }

  virtual ~Split_mouseEventFunc_args() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  int16_t button;
  int16_t x;
  int16_t y;

  struct __isset {
    __isset() : button(false), x(false), y(false) {}
    bool button;
    bool x;
    bool y;
  } __isset;

  bool operator == (const Split_mouseEventFunc_args & rhs) const
  {
    if (!(button == rhs.button))
      return false;
    if (!(x == rhs.x))
      return false;
    if (!(y == rhs.y))
      return false;
    return true;
  }
  bool operator != (const Split_mouseEventFunc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Split_mouseEventFunc_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_mouseEventFunc_pargs {
 public:


  virtual ~Split_mouseEventFunc_pargs() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  const int16_t* button;
  const int16_t* x;
  const int16_t* y;

  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_mouseMotionFunc_args {
 public:

  Split_mouseMotionFunc_args() : x(0), y(0) {
  }

  virtual ~Split_mouseMotionFunc_args() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  int16_t x;
  int16_t y;

  struct __isset {
    __isset() : x(false), y(false) {}
    bool x;
    bool y;
  } __isset;

  bool operator == (const Split_mouseMotionFunc_args & rhs) const
  {
    if (!(x == rhs.x))
      return false;
    if (!(y == rhs.y))
      return false;
    return true;
  }
  bool operator != (const Split_mouseMotionFunc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Split_mouseMotionFunc_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_mouseMotionFunc_pargs {
 public:


  virtual ~Split_mouseMotionFunc_pargs() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  const int16_t* x;
  const int16_t* y;

  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_reshapeFunc_args {
 public:

  Split_reshapeFunc_args() : x(0), y(0) {
  }

  virtual ~Split_reshapeFunc_args() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  int16_t x;
  int16_t y;

  struct __isset {
    __isset() : x(false), y(false) {}
    bool x;
    bool y;
  } __isset;

  bool operator == (const Split_reshapeFunc_args & rhs) const
  {
    if (!(x == rhs.x))
      return false;
    if (!(y == rhs.y))
      return false;
    return true;
  }
  bool operator != (const Split_reshapeFunc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Split_reshapeFunc_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_reshapeFunc_pargs {
 public:


  virtual ~Split_reshapeFunc_pargs() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;

  const int16_t* x;
  const int16_t* y;

  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_idle_args {
 public:

  Split_idle_args() {
  }

  virtual ~Split_idle_args() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;


  bool operator == (const Split_idle_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Split_idle_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Split_idle_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class Split_idle_pargs {
 public:


  virtual ~Split_idle_pargs() throw() {}

  static apache::thrift::reflection::local::TypeSpec* local_reflection;


  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class SplitClient : virtual public SplitIf {
 public:
  SplitClient(boost::shared_ptr<apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  SplitClient(boost::shared_ptr<apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr<apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr<apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void display(std::string& _return);
  void send_display();
  void recv_display(std::string& _return);
  void keyboardEventFunc(const int8_t key, const int16_t x, const int16_t y);
  void send_keyboardEventFunc(const int8_t key, const int16_t x, const int16_t y);
  void mouseEventFunc(const int16_t button, const int16_t x, const int16_t y);
  void send_mouseEventFunc(const int16_t button, const int16_t x, const int16_t y);
  void mouseMotionFunc(const int16_t x, const int16_t y);
  void send_mouseMotionFunc(const int16_t x, const int16_t y);
  void reshapeFunc(const int16_t x, const int16_t y);
  void send_reshapeFunc(const int16_t x, const int16_t y);
  void idle();
  void send_idle();
 protected:
  boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot_;
  apache::thrift::protocol::TProtocol* iprot_;
  apache::thrift::protocol::TProtocol* oprot_;
};

class SplitProcessor : virtual public apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<SplitIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid);
 private:
  std::map<std::string, void (SplitProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*)> processMap_;
  void process_display(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
  void process_keyboardEventFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
  void process_mouseEventFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
  void process_mouseMotionFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
  void process_reshapeFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
  void process_idle(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
 public:
  SplitProcessor(boost::shared_ptr<SplitIf> iface) :
    iface_(iface) {
    processMap_["display"] = &SplitProcessor::process_display;
    processMap_["keyboardEventFunc"] = &SplitProcessor::process_keyboardEventFunc;
    processMap_["mouseEventFunc"] = &SplitProcessor::process_mouseEventFunc;
    processMap_["mouseMotionFunc"] = &SplitProcessor::process_mouseMotionFunc;
    processMap_["reshapeFunc"] = &SplitProcessor::process_reshapeFunc;
    processMap_["idle"] = &SplitProcessor::process_idle;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot);
  virtual ~SplitProcessor() {}
};

class SplitMultiface : virtual public SplitIf {
 public:
  SplitMultiface(std::vector<boost::shared_ptr<SplitIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SplitMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SplitIf> > ifaces_;
  SplitMultiface() {}
  void add(boost::shared_ptr<SplitIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void display(std::string& _return) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->display(_return);
        return;
      } else {
        ifaces_[i]->display(_return);
      }
    }
  }

  void keyboardEventFunc(const int8_t key, const int16_t x, const int16_t y) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->keyboardEventFunc(key, x, y);
    }
  }

  void mouseEventFunc(const int16_t button, const int16_t x, const int16_t y) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->mouseEventFunc(button, x, y);
    }
  }

  void mouseMotionFunc(const int16_t x, const int16_t y) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->mouseMotionFunc(x, y);
    }
  }

  void reshapeFunc(const int16_t x, const int16_t y) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->reshapeFunc(x, y);
    }
  }

  void idle() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->idle();
    }
  }

};

} // namespace

#endif