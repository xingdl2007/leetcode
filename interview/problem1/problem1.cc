/*
 * sword to offer: problem 1
 */
#include <string.h>

class MyString {
 public:
  CMyString(char* pData = NULL);
  CMyString(const CMyString& str);
  ~CMystring(void);
  // prototype
  CMyString& operator=(const CMyString& str);
 private:
  // be careful of this pointer type
  char* m_pData;        
};

// method one: general
CMyString& CMyString::operator=(const CMyString& str) {
  if(*this != str) {
    delete[] m_pData; m_pData = NULL;
    m_pData = new char[strlen(m_pData+1)];
    //memcpy(m_pData,str.m_pData,strlen(m_pData)+1);
    strcpy(m_pData,str.m_pData);
  }
  return *this;
}

// method two: little promote
CMyString& CMyString::operator=(const CMyString& str) {
  if(*this != str) {
    char *tmp = new char[strlen(m_pData+1)];
    strcpy(tmp,str.m_pData);
    delete[] m_pData;
    m_pData = tmp;
  }
  return *this;
}

// method three: perfect
// best practise: C'tor/D'tor does the dirty job
CMyString& CMyString::operator=(const CMyString& str) {
  if(*this != str) {
    CMyString tmp(str);
    char *ptmp = tmp.m_pData;
    tmp.m_pData = m_pData;
    m_pData = ptmp;
  }
  return *this;
}
