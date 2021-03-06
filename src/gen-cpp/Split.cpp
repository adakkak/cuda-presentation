/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#include "Split.h"

namespace split {

uint32_t Split_display_args::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_display_args::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_display_args");
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_display_pargs::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_display_pargs");
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_display_result::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_display_result::write(apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("Split_display_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_display_presult::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_keyboardEventFunc_args::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case -1:
        if (ftype == apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->x);
          this->__isset.x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -3:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->y);
          this->__isset.y = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_keyboardEventFunc_args::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_keyboardEventFunc_args");
  xfer += oprot->writeFieldBegin("key", apache::thrift::protocol::T_BYTE, -1);
  xfer += oprot->writeByte(this->key);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16(this->x);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -3);
  xfer += oprot->writeI16(this->y);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_keyboardEventFunc_pargs::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_keyboardEventFunc_pargs");
  xfer += oprot->writeFieldBegin("key", apache::thrift::protocol::T_BYTE, -1);
  xfer += oprot->writeByte((*(this->key)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16((*(this->x)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -3);
  xfer += oprot->writeI16((*(this->y)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_mouseEventFunc_args::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case -1:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->button);
          this->__isset.button = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->x);
          this->__isset.x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -3:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->y);
          this->__isset.y = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_mouseEventFunc_args::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_mouseEventFunc_args");
  xfer += oprot->writeFieldBegin("button", apache::thrift::protocol::T_I16, -1);
  xfer += oprot->writeI16(this->button);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16(this->x);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -3);
  xfer += oprot->writeI16(this->y);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_mouseEventFunc_pargs::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_mouseEventFunc_pargs");
  xfer += oprot->writeFieldBegin("button", apache::thrift::protocol::T_I16, -1);
  xfer += oprot->writeI16((*(this->button)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16((*(this->x)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -3);
  xfer += oprot->writeI16((*(this->y)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_mouseMotionFunc_args::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case -1:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->x);
          this->__isset.x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->y);
          this->__isset.y = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_mouseMotionFunc_args::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_mouseMotionFunc_args");
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -1);
  xfer += oprot->writeI16(this->x);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16(this->y);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_mouseMotionFunc_pargs::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_mouseMotionFunc_pargs");
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -1);
  xfer += oprot->writeI16((*(this->x)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16((*(this->y)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_reshapeFunc_args::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case -1:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->x);
          this->__isset.x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->y);
          this->__isset.y = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_reshapeFunc_args::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_reshapeFunc_args");
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -1);
  xfer += oprot->writeI16(this->x);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16(this->y);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_reshapeFunc_pargs::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_reshapeFunc_pargs");
  xfer += oprot->writeFieldBegin("x", apache::thrift::protocol::T_I16, -1);
  xfer += oprot->writeI16((*(this->x)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("y", apache::thrift::protocol::T_I16, -2);
  xfer += oprot->writeI16((*(this->y)));
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_idle_args::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Split_idle_args::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_idle_args");
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Split_idle_pargs::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Split_idle_pargs");
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void SplitClient::display(std::string& _return)
{
  send_display();
  recv_display(_return);
}

void SplitClient::send_display()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("display", apache::thrift::protocol::T_CALL, cseqid);

  Split_display_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->flush();
  oprot_->getTransport()->writeEnd();
}

void SplitClient::recv_display(std::string& _return)
{

  int32_t rseqid = 0;
  std::string fname;
  apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == apache::thrift::protocol::T_EXCEPTION) {
    apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != apache::thrift::protocol::T_REPLY) {
    iprot_->skip(apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw apache::thrift::TApplicationException(apache::thrift::TApplicationException::INVALID_MESSAGE_TYPE);
  }
  if (fname.compare("display") != 0) {
    iprot_->skip(apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw apache::thrift::TApplicationException(apache::thrift::TApplicationException::WRONG_METHOD_NAME);
  }
  Split_display_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  throw apache::thrift::TApplicationException(apache::thrift::TApplicationException::MISSING_RESULT, "display failed: unknown result");
}

void SplitClient::keyboardEventFunc(const int8_t key, const int16_t x, const int16_t y)
{
  send_keyboardEventFunc(key, x, y);
}

void SplitClient::send_keyboardEventFunc(const int8_t key, const int16_t x, const int16_t y)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("keyboardEventFunc", apache::thrift::protocol::T_CALL, cseqid);

  Split_keyboardEventFunc_pargs args;
  args.key = &key;
  args.x = &x;
  args.y = &y;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->flush();
  oprot_->getTransport()->writeEnd();
}

void SplitClient::mouseEventFunc(const int16_t button, const int16_t x, const int16_t y)
{
  send_mouseEventFunc(button, x, y);
}

void SplitClient::send_mouseEventFunc(const int16_t button, const int16_t x, const int16_t y)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("mouseEventFunc", apache::thrift::protocol::T_CALL, cseqid);

  Split_mouseEventFunc_pargs args;
  args.button = &button;
  args.x = &x;
  args.y = &y;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->flush();
  oprot_->getTransport()->writeEnd();
}

void SplitClient::mouseMotionFunc(const int16_t x, const int16_t y)
{
  send_mouseMotionFunc(x, y);
}

void SplitClient::send_mouseMotionFunc(const int16_t x, const int16_t y)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("mouseMotionFunc", apache::thrift::protocol::T_CALL, cseqid);

  Split_mouseMotionFunc_pargs args;
  args.x = &x;
  args.y = &y;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->flush();
  oprot_->getTransport()->writeEnd();
}

void SplitClient::reshapeFunc(const int16_t x, const int16_t y)
{
  send_reshapeFunc(x, y);
}

void SplitClient::send_reshapeFunc(const int16_t x, const int16_t y)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("reshapeFunc", apache::thrift::protocol::T_CALL, cseqid);

  Split_reshapeFunc_pargs args;
  args.x = &x;
  args.y = &y;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->flush();
  oprot_->getTransport()->writeEnd();
}

void SplitClient::idle()
{
  send_idle();
}

void SplitClient::send_idle()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("idle", apache::thrift::protocol::T_CALL, cseqid);

  Split_idle_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->flush();
  oprot_->getTransport()->writeEnd();
}

bool SplitProcessor::process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot) {

  apache::thrift::protocol::TProtocol* iprot = piprot.get();
  apache::thrift::protocol::TProtocol* oprot = poprot.get();
  std::string fname;
  apache::thrift::protocol::TMessageType mtype;
  int32_t seqid;

  iprot->readMessageBegin(fname, mtype, seqid);

  if (mtype != apache::thrift::protocol::T_CALL) {
    iprot->skip(apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    apache::thrift::TApplicationException x(apache::thrift::TApplicationException::INVALID_MESSAGE_TYPE);
    oprot->writeMessageBegin(fname, apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->flush();
    oprot->getTransport()->writeEnd();
    return true;
  }

  return process_fn(iprot, oprot, fname, seqid);
}

bool SplitProcessor::process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid) {
  std::map<std::string, void (SplitProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*)>::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    apache::thrift::TApplicationException x(apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->flush();
    oprot->getTransport()->writeEnd();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot);
  return true;
}

void SplitProcessor::process_display(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot)
{
  Split_display_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  iprot->getTransport()->readEnd();

  Split_display_result result;
  try {
    iface_->display(result.success);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("display", apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->flush();
    oprot->getTransport()->writeEnd();
    return;
  }

  oprot->writeMessageBegin("display", apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  oprot->getTransport()->flush();
  oprot->getTransport()->writeEnd();
}

void SplitProcessor::process_keyboardEventFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot)
{
  Split_keyboardEventFunc_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  iprot->getTransport()->readEnd();

  try {
    iface_->keyboardEventFunc(args.key, args.x, args.y);
  } catch (const std::exception& e) {
  }
  return;
}

void SplitProcessor::process_mouseEventFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot)
{
  Split_mouseEventFunc_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  iprot->getTransport()->readEnd();

  try {
    iface_->mouseEventFunc(args.button, args.x, args.y);
  } catch (const std::exception& e) {
  }
  return;
}

void SplitProcessor::process_mouseMotionFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot)
{
  Split_mouseMotionFunc_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  iprot->getTransport()->readEnd();

  try {
    iface_->mouseMotionFunc(args.x, args.y);
  } catch (const std::exception& e) {
  }
  return;
}

void SplitProcessor::process_reshapeFunc(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot)
{
  Split_reshapeFunc_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  iprot->getTransport()->readEnd();

  try {
    iface_->reshapeFunc(args.x, args.y);
  } catch (const std::exception& e) {
  }
  return;
}

void SplitProcessor::process_idle(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot)
{
  Split_idle_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  iprot->getTransport()->readEnd();

  try {
    iface_->idle();
  } catch (const std::exception& e) {
  }
  return;
}

} // namespace

