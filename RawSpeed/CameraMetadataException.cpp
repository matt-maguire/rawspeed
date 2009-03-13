#include "StdAfx.h"
#include "CameraMetadataException.h"

void ThrowCME(const char* fmt, ...) {
  va_list val;
  va_start(val, fmt);
  char buf[8192];
#ifdef __unix__
  vsnprintf(buf, 8192, fmt, val);
#else
  vsprintf_s(buf, 8192, fmt, val);
#endif
  va_end(val);
  _RPT1(0, "EXCEPTION: %s\n",buf);
  throw CameraMetadataException(buf);
}

CameraMetadataException::CameraMetadataException(const string _msg): runtime_error(_msg)
{
  _RPT1(0, "CameraMetadata Exception: %s\n", _msg.c_str());
}
