#ifndef __NAMELIST_HPP__
#define __NAMELIST_HPP__
/*
namelist.hpp

������ ���� ������, ������������ � viewer ��� ������� Gray+/Gray-

*/

/* Revision: 1.04 06.08.2004 $ */

/*
Modify:
  06.08.2004 SKV
    ! see 01825.MSVCRT.txt
  19.11.2003 IS
    + ������ �� ������� (TList) �� ������ ����, ���������� KS, �����
      ���������� ��� ��������.
    ! ��������� const
    + ������ �� ������������ ������ � GetNextName/GetPrevName
    ! MoveData �������� �� �������, � �� ����������
  14.10.2003 SVS
    ! �������� � NamesList.
    ! NamesList::GetCurDir - ����� ���. �������� - ��������� ������.
    + NamesList::Init()
  06.05.2001 DJ
    ! �������� #include
  25.06.2000 SVS
    ! ���������� Master Copy
    ! ��������� � �������� ���������������� ������
*/

#include "farconst.hpp"
#include "TList.hpp"
#include "plugin.hpp"
#include "fn.hpp"

class NamesList
{
  private:
    struct OneName
    {
      char Value[MAX_PATH];
      OneName()
      {
        Value[0]=0;
      }
      // ��� ��������������� �������� ��������� ��� � xstrncpy!
      const OneName& operator=(const char *rhs)
      {
        xstrncpy(Value,rhs,sizeof(Value)-1);
        return *this;
      }
    };

    typedef TList<OneName> StrList;

    StrList Names;
    OneName CurName;
    const OneName *pCurName;


    char CurDir[NM];

  private:
    void Init();

  public:
    NamesList();
    ~NamesList();

  public:
    void AddName(const char *Name);
    bool GetNextName(char *Name, const size_t NameSize);
    bool GetPrevName(char *Name, const size_t NameSize);
    void SetCurName(const char *Name);
    void MoveData(NamesList &Dest);
    void GetCurDir(char *Dir,int DestSize);
    void SetCurDir(const char *Dir);
};

#endif  // __NAMELIST_HPP__
