#if defined(DHELP2)
#include "help2.cpp"
#else
/*
help.cpp

������

*/

/* Revision: 1.46 07.10.2001 $ */

/*
Modify:
  07.10.2001 SVS
    + Opt.HelpTabSize - ������ ��������� �� ���������.
  01.10.2001 SVS
    ! �������� �������� "KEY_SHIFTF3"
    + CtrlTabSize - �����! ������ ��������� - ������ �� �������!
  27.09.2001 IS
    - ����� ������ ��� ������������� strncpy
  24.09.2001 VVM
    ! ������� ������� ������ ��� ������. ����� ����� ������ ��� ������� �������...
  19.09.2001 VVM
    + �������� ��������� �� ������.
  21.08.2001 KM
    - ������� ���������� ����� � ������ ������ �������,
      � ������� ���� ��� ������ ������ ������������� "/".
  20.08.2001 VVM
    ! ��������� ��������� � ������.
  07.08.2001 SVS
    ! ��������� - ��� ����������� ���� (�� ������ help2.?pp)
  05.08.2001 SVS
    + AddTitle() - �������� ����.
    ! � Help::MkTopic() �������� ����������� ���������� ������������ ������,
      ���� �� ��� �����������. ����� ��� ����� ������������, �.�. ���� ����
      ���������:
        � �������, ���� ������� ��� �������, ��� ��� ������ ������ ��������
        ".ext" (�����), �� ��� �������� �� ���.
  03.08.2001 SVS
    - ���� � ������� �����.
  01.08.2001 SVS
    + ����� ������ �� �����
    + ������� - "��������� ����������" (����� ������)
  26.07.2001 VVM
    + � ������ ������� ������ �� 1
  22.07.2001 SVS
    ! ��������� number two - �������� ��� �������� �������� ���������
      ������������ ����� (�� ����, ���)
  20.07.2001 SVS
    - "��-��-���-��" :-( (��� ���������� ������ �����)
    ! PluginPanelHelp ��������� � �������� (�� ����� �� �����)
    ! ������� �� ������������� Get/Set-FullScreenMode
  20.07.2001 SVS
    - F1 Esc - ��������
  20.07.2001 SVS
    ! "�������� �������" Help API. Part I.
  11.07.2001 SVS
    - ���������� �������� � ��������� ������� �� ��������� ������� ���
      ������� ���� �����
  11.07.2001 OT
    ! ������� CtrlAltShift � Manager
  10.07.2001 OT
    - ���������� ���������� static SaveScreen *TopScreen � TopLevel :)
  20.06.2001 SVS
    - ���������� �������� � Alt-F9
  14.06.2001 OT
    ! "����" ;-)
  04.06.2001 OT
    - ������������� ����������� F1->AltF9.
      ���������� ���������� static SaveScreen *TopScreen � TopLevel �� �������������
  31.05.2001 OT
    + ResizeConsole()
    - ����������� F1->AltF9-> ?? �������� ��������� ���������,
      ��������� �� ScreenSave��, ��... ��� ���� ����� :)
  26.05.2001 OT
    - ����������� ������ ������� � NFZ
    - �� ��������� ����� ��������� ����������.
  16.05.2001 DJ
    ! proof-of-concept
  15.05.2001 OT
    ! NWZ -> NFZ
  07.05.2001 DJ
    ! ��������� mouse wheel
    - ������ �� ����������
  06.05.2001 DJ
    ! �������� #include
  26.04.2001 DJ
    - ���������� ����������� Mask ��� ��������� F5
  16.04.2001 SVS
    - �� ������� SelTopic, ���� � ��� � "Help on Help"
  12.04.2001 SVS
    + ���������� �������� Mask, ����������� � ����������� (��� ����������
      ������ HlfViewer)
    - �� �������� ���������������� ������� F1, Shift-F1, Enter
  26.03.2001 SVS
    + FHELP_USECONTENTS - ���� �� ������ ������� �����, �� ���������� "Contents"
    ! ReadHelp ���������� TRUE/FALSE
  21.03.2001 VVM
    ! ��������� ��������� ������� '$'
  16.03.2001 VVM
    ! ���� ����� �� ������ - ��������, ��� ����
    - � ������� ReadPluginsHelp ���������������� CtrlColorChar
  22.02.2001 SVS
    ! � ���������� ������ ������� �������� ~~ � ## �� ��������� �����������
  06.02.2001 SVS
    - ���������(?) ��� � �����������...
      (����� ����� ���� �� ������� - �������� ����� �������� ��� ������)
  20.01.2001 SVS
    - �������� ������ ��� ������ �������.
      ���� ��������� �� 354-� �����, ����� ���� ������� ��������� �����
  18.12.2000 SVS
    + �������������� �������� � ������������ - DWORD Flags.
    + ��������� ���� FHELP_NOSHOWERROR
  18.12.2000 SVS
    - ExpandEnv ����� ��������� � ���������� :-(
  07.12.2000 SVS
    ! ������� �������� ������� URL ���������� - ���� ��������� �� �������
      ���������� ��������.
  27.09.2000 SVS
    ! ���������� ��� ����������� URL-������.
    ! Ctrl-Alt-Shift - ���������, ���� ����.
  19.09.2000 OT
    - ������ ��� ��������� �����
  12.09.2000 SVS
    + ��������� � ������� ReadHelp � ������������, �������� ����� ������
      ������.
  01.09.2000 SVS
    + ��� ������� �������� �������� - ����� ������ CtrlColorChar
  25.08.2000 SVS
    + CtrlAltShift - ��������/�������� ������...
    + URL ��������� - ��� ���� ��� ������ :-)))
  13.07.2000 SVS
    ! ��������� ��������� ��� ������������� new/delete/realloc
  28.06.2000
    - NT Console resize
      adding SetScreenPosition method
  26.06.2000 IS
    - ���� � ������ �� f1, shift+f2, end
      (������� ��������� IG)
  25.06.2000 SVS
    ! ���������� Master Copy
    ! ��������� � �������� ���������������� ������
*/

#include "headers.hpp"
#pragma hdrstop

#include "help.hpp"
#include "global.hpp"
#include "fn.hpp"
#include "lang.hpp"
#include "keys.hpp"
#include "colors.hpp"
#include "plugin.hpp"
#include "scantree.hpp"
#include "savescr.hpp"
#include "manager.hpp"
#include "ctrlobj.hpp"


// ���� ��������
class CallBackStack
{
  private:
    struct ListNode
    {
      ListNode *Next;

      DWORD Flags;             // �����
      int   TopStr;            // ����� ������� ������� ������ ����
      int   CurX,CurY;         // ���������� (???)

      char  *HelpTopic;        // ������� �����
      char  *HelpPath;         // ���� � ������
      char  *SelTopic;         // ������� ���������

      ListNode(const struct StackHelpData *Data, ListNode* n=NULL)
      {
        HelpTopic=strdup(Data->HelpTopic);
        HelpPath=strdup(Data->HelpPath);
        SelTopic=strdup(Data->SelTopic);
        Flags=Data->Flags;
        TopStr=Data->TopStr;
        CurX=Data->CurX;
        CurY=Data->CurY;

        Next=n;
      }
      ~ListNode()
      {
        if(HelpTopic) free(HelpTopic);
        if(HelpPath)  free(HelpPath);
        if(SelTopic)  free(SelTopic);
      }
    };

    ListNode *topOfStack;

  public:
    CallBackStack() {topOfStack=NULL;};
   ~CallBackStack() {ClearStack();};

  public:
    void ClearStack();
    BOOL isEmpty() const {return topOfStack==NULL;};

    void Push(const struct StackHelpData *Data);
    int Pop(struct StackHelpData *Data=NULL);

    void PrintStack(const char *Title);
};


#define MAX_HELP_STRING_LENGTH 300

static const char *PluginContents="__PluginContents__";
static const char *DocumentContents="__DocumentContents__";
static const char *HelpOnHelpTopic="Help";
static const char *HelpContents="Contents";

static int RunURL(char *Protocol, char *URLPath);

Help::Help(char *Topic, char *Mask,DWORD Flags)
{
  /* $ OT �� ��������� ��� ����� ��������� ����������*/
  SetDynamicallyBorn(FALSE);
  CanLoseFocus=FALSE;
  PrevMacroMode=CtrlObject->Macro.GetMode();
  CtrlObject->Macro.SetMode(MACRO_HELP);

  ErrorHelp=TRUE;
  IsNewTopic=TRUE;

  Stack=new CallBackStack;

  memset(&StackData,0,sizeof(StackData));
  StackData.Flags=Flags;

  /* $ 01.09.2000 SVS
     ��������� �� ��������� ������� ���� ���������...
  */
  CurColor=COL_HELPTEXT;
  /* SVS $ */

  HelpMask=Mask?strdup(Mask):NULL; // �������� ����� �����

  KeyBarVisible = TRUE;  // �������� ���������� ������
  TopScreen=new SaveScreen;
  HelpData=NULL;
  strcpy(StackData.HelpTopic,Topic);
  *StackData.HelpPath=0;
  if (Opt.FullScreenHelp)
    SetPosition(0,0,ScrX,ScrY);
  else
    SetPosition(4,2,ScrX-4,ScrY-2);

  if(!ReadHelp(Mask) && (Flags&FHELP_USECONTENTS))
  {
    strcpy(StackData.HelpTopic,Topic);
    if(*StackData.HelpTopic == HelpBeginLink)
    {
      char *Ptr=strrchr(StackData.HelpTopic,HelpEndLink);
      if(Ptr)
        strcpy(++Ptr,HelpContents);
    }
    *StackData.HelpPath=0;
    ReadHelp(Mask);
  }

  if (HelpData!=NULL)
  {
    InitKeyBar();
    MacroMode = MACRO_HELP;
    MoveToReference(1,1);
    FrameManager->ExecuteModal (this);//OT
  }
  else
  {
    if(!(Flags&FHELP_NOSHOWERROR))
      Message(MSG_WARNING,1,MSG(MHelpTitle),MSG(MHelpTopicNotFound),MSG(MOk));
    ErrorHelp=TRUE;
  }
}

Help::~Help()
{
  CtrlObject->Macro.SetMode(PrevMacroMode);
  SetRestoreScreenMode(FALSE);

  if(HelpData)     free(HelpData);
  if(Stack)        delete Stack;
  if(HelpMask)     delete HelpMask;
  if(TopScreen)    delete TopScreen;
}


void Help::Hide()
{
  ScreenObject::Hide();
}


int Help::ReadHelp(char *Mask)
{
  char FileName[NM],ReadStr[2*MAX_HELP_STRING_LENGTH];
  char SplitLine[2*MAX_HELP_STRING_LENGTH+8],*Ptr;
  int Formatting=TRUE,RepeatLastLine,PosTab;
  const int MaxLength=X2-X1-1;
  char TabSpace[32];

  DisableOut=0;

  char Path[NM],*TopicPtr;
  if (*StackData.HelpTopic==HelpBeginLink)
  {
    strcpy(Path,StackData.HelpTopic+1);
    if ((TopicPtr=strchr(Path,HelpEndLink))==NULL)
      return FALSE;
    strcpy(StackData.HelpTopic,TopicPtr+1);
    *TopicPtr=0;
    strcpy(StackData.HelpPath,Path);
  }
  else
    strcpy(Path,*StackData.HelpPath ? StackData.HelpPath:FarPath);

  if (!strcmp(StackData.HelpTopic,PluginContents))
  {
    ReadDocumentsHelp(HIDX_PLUGINS);
    return TRUE;
  }

  if (!strcmp(StackData.HelpTopic,DocumentContents))
  {
    ReadDocumentsHelp(HIDX_DOCUMS);
    return TRUE;
  }

  FILE *HelpFile=Language::OpenLangFile(Path,(!Mask?HelpFileMask:Mask),Opt.HelpLanguage,FileName);

  if (HelpFile==NULL)
  {
    if(!(StackData.Flags&FHELP_NOSHOWERROR))
      Message(MSG_WARNING|MSG_ERRORTYPE,1,MSG(MHelpTitle),MSG(MCannotOpenHelp),FileName,MSG(MOk));
    ErrorHelp=TRUE;
    return FALSE;
  }

  *ReadStr=0;
  if (Language::GetOptionsParam(HelpFile,"TabSize",ReadStr))
  {
    CtrlTabSize=atoi(ReadStr);
  }
  if(CtrlTabSize < 0 || CtrlTabSize > 16)
    CtrlTabSize=Opt.HelpTabSize;

  *ReadStr=0;
  if (Language::GetOptionsParam(HelpFile,"CtrlColorChar",ReadStr))
  {
    CtrlColorChar=ReadStr[0];
  }
  else
    CtrlColorChar=0;
  *SplitLine=0;
  if (HelpData)
    free(HelpData);
  HelpData=NULL;
  StrCount=0;
  FixCount=0;
  TopicFound=0;
  RepeatLastLine=FALSE;
  int NearTopicFound=0;
  char PrevSymbol=0;

  memset(TabSpace,' ',sizeof(TabSpace)-1);
  TabSpace[sizeof(TabSpace)-1]=0;

  while (TRUE)
  {
    if (!RepeatLastLine && fgets(ReadStr,sizeof(ReadStr)/2,HelpFile)==NULL)
    {
      if (StringLen(SplitLine)<MaxLength)
      {
        if (*SplitLine)
          AddLine(SplitLine);
      }
      else
      {
        *ReadStr=0;
        RepeatLastLine=TRUE;
        continue;
      }
      break;
    }
    RepeatLastLine=FALSE;

    while((Ptr=strchr(ReadStr,'\t')) != NULL)
    {
      *Ptr=' ';
      PosTab=Ptr-ReadStr+1;
      if(CtrlTabSize > 1) // ������� ��������� �� ���� ���������
        InsertString(ReadStr,PosTab,TabSpace,
           ((PosTab%CtrlTabSize)==0?CtrlTabSize:(PosTab%CtrlTabSize))-1);
      if(strlen(ReadStr) > sizeof(ReadStr)/2)
        break;
    }

    RemoveTrailingSpaces(ReadStr);

    if (TopicFound)
      HighlightsCorrection(ReadStr);

    if (*ReadStr=='@')
    {
      if (TopicFound)
      {
        if (strcmp(ReadStr,"@+")==0)
        {
          Formatting=TRUE;
          PrevSymbol=0;
          continue;
        }
        if (strcmp(ReadStr,"@-")==0)
        {
          Formatting=FALSE;
          PrevSymbol=0;
          continue;
        }
        if (*SplitLine)
          AddLine(SplitLine);
        break;
      }
      else
        if (LocalStricmp(ReadStr+1,StackData.HelpTopic)==0)
        {
          TopicFound=1;
          NearTopicFound=1;
        }
    }
    else
      if (TopicFound)
      {
        /* $<text> � ������ ������, ����������� ����
           ���������� �� �������������� ������� ������
           ���� ���� ��������� ������ ����� ����� ������ ����������� ����...
        */
        if (*ReadStr=='$' && NearTopicFound && (PrevSymbol == '$' || PrevSymbol == '@'))
        {
          AddLine(ReadStr+1);
          FixCount++;
        }
        else
        {
          NearTopicFound=0;
          if (*ReadStr==0 || !Formatting)
            if (*SplitLine)
              if (StringLen(SplitLine)<MaxLength)
              {
                AddLine(SplitLine);
                *SplitLine=0;
                if (StringLen(ReadStr)<MaxLength)
                {
                  AddLine(ReadStr);
                  continue;
                }
              }
              else
                RepeatLastLine=TRUE;
            else
              if (StringLen(ReadStr)<MaxLength)
              {
                AddLine(ReadStr);
                continue;
              }
          if (isspace(*ReadStr) && Formatting)
            if (StringLen(SplitLine)<MaxLength)
            {
              if (*SplitLine)
                AddLine(SplitLine);
              strcpy(SplitLine,ReadStr);
              *ReadStr=0;
              continue;
            }
            else
              RepeatLastLine=TRUE;
          if (!RepeatLastLine)
          {
            if (*SplitLine)
              strcat(SplitLine," ");
            strcat(SplitLine,ReadStr);
          }
          if (StringLen(SplitLine)<MaxLength)
            continue;
          int Splitted=0;
          for (int I=strlen(SplitLine)-1;I>0;I--)
          {
            if (I>0 && SplitLine[I]=='~' && SplitLine[I-1]=='~')
            {
              I--;
              continue;
            }
            if (I>0 && SplitLine[I]=='~' && SplitLine[I-1]!='~')
            {
              do {
                I--;
              } while (I>0 && SplitLine[I]!='~');
              continue;
            }
            if (SplitLine[I]==' ')
            {
              SplitLine[I]=0;
              if (StringLen(SplitLine)<MaxLength)
              {
                AddLine(SplitLine);
                memmove(SplitLine+1,SplitLine+I+1,strlen(SplitLine+I+1)+1);
                *SplitLine=' ';
                HighlightsCorrection(SplitLine);
                Splitted=TRUE;
                break;
              }
              else
                SplitLine[I]=' ';
            }
          }
          if (!Splitted)
          {
            AddLine(SplitLine);
            *SplitLine=0;
          }
        }
      }
    PrevSymbol=*ReadStr;
  }

  fclose(HelpFile);
  FixSize=FixCount+(FixCount!=0);
  ErrorHelp=FALSE;
  if(IsNewTopic)
  {
    StackData.CurX=StackData.CurY=0;
    StackData.TopStr=0;
  }
  return TopicFound != 0;
}


void Help::AddLine(char *Line)
{
  char *NewHelpData=(char *)realloc(HelpData,(StrCount+1)*MAX_HELP_STRING_LENGTH);
  if (NewHelpData==NULL)
    return;
  HelpData=NewHelpData;
  strncpy(HelpData+StrCount*MAX_HELP_STRING_LENGTH,Line,MAX_HELP_STRING_LENGTH-1);
  StrCount++;
}

void Help::AddTitle(char *Title)
{
  char IndexHelpTitle[100];
  sprintf(IndexHelpTitle,"^ #%s#",Title);
  AddLine(IndexHelpTitle);
}

void Help::HighlightsCorrection(char *Str)
{
  int I,Count;
  for (I=0,Count=0;Str[I]!=0;I++)
    if (Str[I]=='#')
      Count++;
  if ((Count & 1) && *Str!='$')
  {
    memmove(Str+1,Str,strlen(Str)+1);
    *Str='#';
  }
}


void Help::DisplayObject()
{
  if(!TopScreen)
    TopScreen=new SaveScreen;
  if (!TopicFound)
  {
    if(!(StackData.Flags&FHELP_NOSHOWERROR))
      Message(MSG_WARNING,1,MSG(MHelpTitle),MSG(MHelpTopicNotFound),MSG(MOk));
    ProcessKey(KEY_ALTF1);
    ErrorHelp=TRUE;
    return;
  }
  SetCursorType(0,10);
  if (*StackData.SelTopic==0)
    MoveToReference(1,1);
  FastShow();
  if (!Opt.FullScreenHelp)
  {
    HelpKeyBar.SetPosition(0,ScrY,ScrX,ScrY);
    if(Opt.ShowKeyBar)
       HelpKeyBar.Show();
  }
  else
    HelpKeyBar.Hide();
}


void Help::FastShow()
{
  int I;

  if (!DisableOut)
  {
    SetScreen(X1,Y1,X2,Y2,' ',COL_HELPTEXT);
    Box(X1,Y1,X2,Y2,COL_HELPBOX,DOUBLE_BOX);
    SetColor(COL_HELPBOXTITLE);
    GotoXY(X1+(X2-X1+1-strlen(MSG(MHelpTitle))-2)/2,Y1);
    mprintf(" %s ",MSG(MHelpTitle));
  }
  CorrectPosition();
  *StackData.SelTopic=0;
  /* $ 01.09.2000 SVS
     ��������� �� ��������� ������� ���� ���������...
     ����� ����� ���� ���������� � ����������� ����������
  */
  CurColor=COL_HELPTEXT;
  /* SVS $ */
  for (I=0;I<Y2-Y1-1;I++)
  {
    int StrPos;
    if (I<FixCount)
      StrPos=I;
    else
      if (I==FixCount && FixCount>0)
      {
        if (!DisableOut)
        {
          GotoXY(X1,Y1+I+1);
          SetColor(COL_HELPBOX);
          ShowSeparator(X2-X1+1);
        }
        continue;
      }
      else
      {
        StrPos=I+StackData.TopStr;
        if (FixCount>0)
          StrPos--;
      }
    if (StrPos<StrCount)
    {
      char *OutStr=HelpData+StrPos*MAX_HELP_STRING_LENGTH;
      if (*OutStr=='^')
      {
        GotoXY(X1+(X2-X1+1-StringLen(OutStr))/2,Y1+I+1);
        OutStr++;
      }
      else
        GotoXY(X1+1,Y1+I+1);
      OutString(OutStr);
    }
  }

  const int ScrollLength=Y2-Y1-FixSize-1;
  if (!DisableOut && StrCount-FixCount > ScrollLength)
  {
    int Scrolled=StrCount-FixCount-ScrollLength;
    SetColor(COL_HELPSCROLLBAR);
    ScrollBar(X2,Y1+FixSize+1,ScrollLength,StackData.TopStr,Scrolled);
  }
}

/* $ 01.09.2000 SVS
  ����� ������ CtrlColorChar & CurColor
*/
void Help::OutString(char *Str)
{
  char OutStr[512],*StartTopic=NULL;
  int OutPos=0,Highlight=0,Topic=0;
  while (OutPos<sizeof(OutStr)-10)
  {
    if (Str[0]=='~' && Str[1]=='~' ||
        Str[0]=='#' && Str[1]=='#' ||
        Str[0]=='@' && Str[1]=='@' ||
        (CtrlColorChar && Str[0]==CtrlColorChar && Str[1]==CtrlColorChar)
        )
    {
      OutStr[OutPos++]=*Str;
      Str+=2;
      continue;
    }

    if (*Str=='~' || *Str=='#' || *Str==HelpBeginLink || *Str==0 || *Str == CtrlColorChar)
    {
      OutStr[OutPos]=0;
      if (Topic)
      {
        int RealCurX,RealCurY;
        RealCurX=X1+StackData.CurX+1;
        RealCurY=Y1+StackData.CurY+FixSize+1;
        if (WhereY()==RealCurY && RealCurX>=WhereX() &&
                RealCurX<WhereX()+(Str-StartTopic)-1)
        {
          SetColor(COL_HELPSELECTEDTOPIC);
          if (Str[1]=='@')
          {
            strncpy(StackData.SelTopic,Str+2,sizeof(StackData.SelTopic)-1);
            char *EndPtr=strchr(StackData.SelTopic,'@');
            /* $ 25.08.2000 SVS
               �����, ��� ����� ���� ����� �������: @@ ��� \@
               ���� ������� ������ ��� URL!
            */
            if (EndPtr!=NULL)
            {
              if(*(EndPtr+1) == '@')
              {
                memmove(EndPtr,EndPtr+1,strlen(EndPtr)+1);
                EndPtr++;
              }
              EndPtr=strchr(EndPtr,'@');
              if (EndPtr!=NULL)
                *EndPtr=0;
            }
            /* SVS $ */
          }
        }
        else
          SetColor(COL_HELPTOPIC);
      }
      else
        if (Highlight)
          SetColor(COL_HELPHIGHLIGHTTEXT);
        else
          SetColor(CurColor);
      /* $ 24.09.2001 VVM
        ! ������� ������� ������ ��� ������. ����� ����� ������ ��� ������� �������... */
      if ((strlen(OutStr) + WhereX()) > X2)
        OutStr[X2 - WhereX()] = 0;
      /* VVM $ */
      if (DisableOut)
        GotoXY(WhereX()+strlen(OutStr),WhereY());
      else
        Text(OutStr);
      OutPos=0;
    }

    if (*Str==0)
      break;

    if (*Str=='~')
    {
      if (!Topic)
        StartTopic=Str;
      Topic=!Topic;
      Str++;
      continue;
    }
    if (*Str=='@')
    {
      /* $ 25.08.2000 SVS
         �����, ��� ����� ���� ����� �������: @@
         ���� ������� ������ ��� URL!
      */
      while (*Str)
        if (*(++Str)=='@' && *(Str-1)!='@')
          break;
      /* SVS $ */
      Str++;
      continue;
    }
    if (*Str=='#')
    {
      Highlight=!Highlight;
      Str++;
      continue;
    }
    if (*Str == CtrlColorChar)
    {
      WORD Chr;

      Chr=(BYTE)Str[1];
      if(Chr == '-') // "\-" - ���������� ���������� ����
      {
        Str+=2;
        CurColor=COL_HELPTEXT;
        continue;
      }
      if(isxdigit(Chr) && isxdigit(Str[2]))
      {
        WORD Attr;

        if(Chr >= '0' && Chr <= '9') Chr-='0';
        else { Chr&=~0x20; Chr=Chr-'A'+10; }
        Attr=(Chr<<4)&0x00F0;

        // next char
        Chr=Str[2];
        if(Chr >= '0' && Chr <= '9') Chr-='0';
        else { Chr&=~0x20; Chr=Chr-'A'+10; }
        Attr|=(Chr&0x000F);
        CurColor=Attr;
        Str+=3;
        continue;
      }
    }

    OutStr[OutPos++]=*(Str++);
  }
  if (!DisableOut && WhereX()<X2)
  {
    SetColor(CurColor);
    mprintf("%*s",X2-WhereX(),"");
  }
}


int Help::StringLen(char *Str)
{
  int Length=0;
  while (*Str)
  {
    if (Str[0]=='~' && Str[1]=='~' ||
        Str[0]=='#' && Str[1]=='#' ||
        Str[0]=='@' && Str[1]=='@' ||
        (CtrlColorChar && Str[0]==CtrlColorChar && Str[1]==CtrlColorChar)
       )
    {
      Length++;
      Str+=2;
      continue;
    }
    if (*Str=='@')
    {
      /* $ 25.08.2000 SVS
         �����, ��� ����� ���� ����� �������: @@
         ���� ������� ������ ��� URL!
      */
      while (*Str)
        if (*(++Str)=='@' && *(Str-1)!='@')
          break;
      /* SVS $ */
      Str++;
      continue;
    }
    /* $ 01.09.2000 SVS
       ����� ���� ������������ \XX ��� \-
    */
    if(*Str == CtrlColorChar)
    {
      if(Str[1] == '-')
      {
        Str+=2;
        continue;
      }

      if(isxdigit(Str[1]) && isxdigit(Str[2]))
      {
        Str+=3;
        continue;
      }
    }
    /* SVS $ */

    if (*Str!='#' && *Str!='~')
      Length++;
    Str++;
  }
  return(Length);
}


void Help::CorrectPosition()
{
  if (StackData.CurX>X2-X1-2)
    StackData.CurX=X2-X1-2;
  if (StackData.CurX<0)
    StackData.CurX=0;
  if (StackData.CurY>Y2-Y1-2-FixSize)
  {
    StackData.TopStr+=StackData.CurY-(Y2-Y1-2-FixSize);
    StackData.CurY=Y2-Y1-2-FixSize;
  }
  if (StackData.CurY<0)
  {
    StackData.TopStr+=StackData.CurY;
    StackData.CurY=0;
  }
  if (StackData.TopStr>StrCount-FixCount-(Y2-Y1-1-FixSize))
    StackData.TopStr=StrCount-FixCount-(Y2-Y1-1-FixSize);
  if (StackData.TopStr<0)
    StackData.TopStr=0;
}


int Help::ProcessKey(int Key)
{
  if (*StackData.SelTopic==0)
    StackData.CurX=StackData.CurY=0;
  switch(Key)
  {
    case KEY_NONE:
    case KEY_IDLE:
      break;
    case KEY_F5:
      Opt.FullScreenHelp=!Opt.FullScreenHelp;
      ResizeConsole();
      return(TRUE);
    case KEY_ESC:
    case KEY_F10:
      FrameManager->DeleteFrame();
      SetExitCode (XC_QUIT);
      return(TRUE);
    case KEY_HOME:
    case KEY_CTRLHOME:
    case KEY_CTRLPGUP:
      StackData.CurX=StackData.CurY=0;
      StackData.TopStr=0;
      FastShow();
      if (*StackData.SelTopic==0)
        MoveToReference(1,1);
      return(TRUE);
    case KEY_END:
    case KEY_CTRLEND:
    case KEY_CTRLPGDN:
      StackData.CurX=StackData.CurY=0;
      StackData.TopStr=StrCount;
      FastShow();
      if (*StackData.SelTopic==0)
      {
        StackData.CurX=0;
        StackData.CurY=Y2-Y1-2-FixSize;
        MoveToReference(0,1);
      }
      return(TRUE);
    case KEY_UP:
      if (StackData.TopStr>0)
      {
        StackData.TopStr--;
        if (StackData.CurY<Y2-Y1-2-FixSize)
        {
          StackData.CurX=X2-X1-2;
          StackData.CurY++;
        }
        FastShow();
        if (*StackData.SelTopic==0)
          MoveToReference(0,1);
      }
      else
        ProcessKey(KEY_SHIFTTAB);
      return(TRUE);
    case KEY_DOWN:
      if (StackData.TopStr<StrCount-FixCount-(Y2-Y1-1-FixSize))
      {
        StackData.TopStr++;
        if (StackData.CurY>0)
          StackData.CurY--;
        StackData.CurX=0;
        FastShow();
        if (*StackData.SelTopic==0)
          MoveToReference(1,1);
      }
      else
        ProcessKey(KEY_TAB);
      return(TRUE);
    /* $ 26.07.2001 VVM
      + � ������ ������� �� 1 */
    /* $ 07.05.2001 DJ
      + ��������� KEY_MSWHEEL_XXXX */
    case KEY_MSWHEEL_UP:
    case (KEY_MSWHEEL_UP | KEY_ALT):
      {
        int Roll = Key & KEY_ALT?1:Opt.MsWheelDelta;
        for (int i=0; i<Roll; i++)
          ProcessKey(KEY_UP);
        return(TRUE);
      }
    case KEY_MSWHEEL_DOWN:
    case (KEY_MSWHEEL_DOWN | KEY_ALT):
      {
        int Roll = Key & KEY_ALT?1:Opt.MsWheelDelta;
        for (int i=0; i<Roll; i++)
          ProcessKey(KEY_DOWN);
        return(TRUE);
      }
    /* DJ $ */
    /* VVM $ */
    case KEY_PGUP:
      StackData.CurX=StackData.CurY=0;
      StackData.TopStr-=Y2-Y1-2-FixSize;
      FastShow();
      if (*StackData.SelTopic==0)
      {
        StackData.CurX=StackData.CurY=0;
        MoveToReference(1,1);
      }
      return(TRUE);
    case KEY_PGDN:
      {
        int PrevTopStr=StackData.TopStr;
        StackData.TopStr+=Y2-Y1-2-FixSize;
        FastShow();
        if (StackData.TopStr==PrevTopStr)
        {
          ProcessKey(KEY_CTRLPGDN);
          return(TRUE);
        }
        else
          StackData.CurX=StackData.CurY=0;
        MoveToReference(1,1);
      }
      return(TRUE);
    case KEY_RIGHT:
    case KEY_TAB:
      MoveToReference(1,0);
      return(TRUE);
    case KEY_LEFT:
    case KEY_SHIFTTAB:
      MoveToReference(0,0);
      return(TRUE);

    case KEY_F1:
      // �� ������� SelTopic, ���� � ��� � Help on Help
      if(LocalStricmp(StackData.HelpTopic,HelpOnHelpTopic)!=0)
      {
        Stack->Push(&StackData);
        IsNewTopic=TRUE;
        JumpTopic(HelpOnHelpTopic);
        IsNewTopic=FALSE;
      }
      return(TRUE);
    case KEY_SHIFTF1:
      //   �� ������� SelTopic, ���� � ��� � ���� Contents
      if(LocalStricmp(StackData.HelpTopic,HelpContents)!=0)
      {
        Stack->Push(&StackData);
        IsNewTopic=TRUE;
        JumpTopic(HelpContents);
        IsNewTopic=FALSE;
      }
      return(TRUE);
    case KEY_SHIFTF2:
      //   �� ������� SelTopic, ���� � ��� � PluginContents
      if(LocalStricmp(StackData.HelpTopic,PluginContents)!=0)
      {
        Stack->Push(&StackData);
        IsNewTopic=TRUE;
        JumpTopic(PluginContents);
        IsNewTopic=FALSE;
      }
      return(TRUE);

    case KEY_SHIFTF3: // ��� "����������" :-)
#if 0
      //   �� ������� SelTopic, ���� � ��� � DocumentContents
      if(LocalStricmp(StackData.HelpTopic,DocumentContents)!=0)
      {
        Stack->Push(&StackData);
        IsNewTopic=TRUE;
        JumpTopic(DocumentContents);
        IsNewTopic=FALSE;
      }
#endif
      return(TRUE);

    case KEY_ALTF1:
    case KEY_BS:
      // ���� ���� �������� ���� - ������� �� �����
      if(!Stack->isEmpty())
      {
        Stack->Pop(&StackData);
        JumpTopic(StackData.HelpTopic);
        return(TRUE);
      }
      return ProcessKey(KEY_ESC);

    case KEY_ENTER:
      if (*StackData.SelTopic && LocalStricmp(StackData.HelpTopic,StackData.SelTopic)!=0)
      {
        Stack->Push(&StackData);
        IsNewTopic=TRUE;
        JumpTopic();
        IsNewTopic=FALSE;
      }
      return(TRUE);
  }
  return(FALSE);
}

int Help::JumpTopic(const char *JumpTopic)
{
  char  OldTopic[512];
  char NewTopic[512];

  Stack->PrintStack(JumpTopic);

  if(JumpTopic)
    strcpy(StackData.SelTopic,JumpTopic);
//_SVS(SysLog("JumpTopic() = SelTopic=%s",StackData.SelTopic));
  // URL ��������� - ��� ���� ��� ������ :-)))
  {
    strcpy(NewTopic,StackData.SelTopic);
    char *p=strchr(NewTopic,':');
    if(p && NewTopic[0] != ':') // �������� ��������������� URL
    {
      *p=0;
      if(RunURL(NewTopic,StackData.SelTopic))
        return(TRUE);
      *p=':';
    }
  }
  // � ��� ������ ���������...

//_SVS(SysLog("JumpTopic() = SelTopic=%s, StackData.HelpPath=%s",StackData.SelTopic,StackData.HelpPath));
  if (*StackData.HelpPath && *StackData.SelTopic!=HelpBeginLink && strcmp(StackData.SelTopic,HelpOnHelpTopic)!=0)
  {
    if (*StackData.SelTopic==':')
      strcpy(NewTopic,StackData.SelTopic+1);
    else
      sprintf(NewTopic,HelpFormatLink,StackData.HelpPath,StackData.SelTopic);
  }
  else
    strcpy(NewTopic,StackData.SelTopic);

//_SVS(SysLog("HelpMask=%s NewTopic=%s",HelpMask,NewTopic));
  if(*StackData.SelTopic != ':' &&
     LocalStricmp(StackData.SelTopic,PluginContents) &&
     LocalStricmp(StackData.SelTopic,DocumentContents))
  {
    ; // :-)
  }
  else
  {
    if(HelpMask)
      free(HelpMask);
    HelpMask=NULL;
  }
  strcpy(StackData.HelpTopic,NewTopic);
  *StackData.HelpPath=0;
  if(!ReadHelp(HelpMask))
  {
    strcpy(StackData.HelpTopic,NewTopic);
    if(*StackData.HelpTopic == HelpBeginLink)
    {
      char *Ptr=strrchr(StackData.HelpTopic,HelpEndLink);
      if(Ptr)
        strcpy(++Ptr,HelpContents);
    }
    *StackData.HelpPath=0;
    ReadHelp(HelpMask);
  }
  if (!HelpData)
  {
    if(!(StackData.Flags&FHELP_NOSHOWERROR))
      Message(MSG_WARNING,1,MSG(MHelpTitle),MSG(MHelpTopicNotFound),MSG(MOk));
    ErrorHelp=TRUE;
    return FALSE;
  }
//  ResizeConsole();
  if(IsNewTopic
    || !LocalStricmp(StackData.SelTopic,PluginContents) // ��� ���������� ������� :-((
    || !LocalStricmp(StackData.SelTopic,DocumentContents))
    MoveToReference(1,1);
  //FrameManager->ImmediateHide();
  FrameManager->RefreshFrame();

  return TRUE;
}



int Help::ProcessMouse(MOUSE_EVENT_RECORD *MouseEvent)
{
  if (MouseEvent->dwEventFlags==MOUSE_MOVED && (MouseEvent->dwButtonState & 3)==0)
    return(FALSE);
  if (MouseEvent->dwMousePosition.X<X1 || MouseEvent->dwMousePosition.X>X2 ||
      MouseEvent->dwMousePosition.Y<Y1 || MouseEvent->dwMousePosition.Y>Y2)
  {
    ProcessKey(KEY_ESC);
    return(TRUE);
  }
  if (MouseX==X2 && (MouseEvent->dwButtonState & 1))
  {
    int ScrollY=Y1+FixSize+1;
    int Height=Y2-Y1-FixSize-1;
    if (MouseY==ScrollY)
    {
      while (IsMouseButtonPressed())
        ProcessKey(KEY_UP);
      return(TRUE);
    }
    if (MouseY==ScrollY+Height-1)
    {
      while (IsMouseButtonPressed())
        ProcessKey(KEY_DOWN);
      return(TRUE);
    }
  }
  if (MouseEvent->dwMousePosition.Y<Y1+1+FixSize)
  {
    while (IsMouseButtonPressed() && MouseY<Y1+1+FixSize)
      ProcessKey(KEY_UP);
    return(TRUE);
  }
  if (MouseEvent->dwMousePosition.Y>=Y2)
  {
    while (IsMouseButtonPressed() && MouseY>=Y2)
      ProcessKey(KEY_DOWN);
    return(TRUE);
  }
  StackData.CurX=MouseEvent->dwMousePosition.X-X1-1;
  StackData.CurY=MouseEvent->dwMousePosition.Y-Y1-1-FixSize;
  FastShow();
  if ((MouseEvent->dwButtonState & 3)==0 && *StackData.SelTopic)
    ProcessKey(KEY_ENTER);
  return(TRUE);
}


int Help::IsReferencePresent()
{
  CorrectPosition();
  int StrPos=FixCount+StackData.TopStr+StackData.CurY;
  /* $ 19.09.2000 OT
    ������ ��� ��������� �����
    */
  if (StrPos >= StrCount) {
    return FALSE;
  }
  /* OT 19.09.2000 $ */
  char *OutStr=HelpData+StrPos*MAX_HELP_STRING_LENGTH;
  return (strchr(OutStr,'@')!=NULL && strchr(OutStr,'~')!=NULL);
}


void Help::MoveToReference(int Forward,int CurScreen)
{
  int StartSelection=*StackData.SelTopic;
  int SaveCurX=StackData.CurX;
  int SaveCurY=StackData.CurY;
  int SaveTopStr=StackData.TopStr;

  *StackData.SelTopic=0;
  DisableOut=TRUE;

  while (*StackData.SelTopic==0)
  {
    if (Forward)
    {
      if (StackData.CurX==0 && !IsReferencePresent())
        StackData.CurX=X2-X1-2;
      if (++StackData.CurX >= X2-X1-2)
      {
        StartSelection=0;
        StackData.CurX=0;
        StackData.CurY++;
        if (StackData.TopStr+StackData.CurY>=StrCount-FixCount ||
            CurScreen && StackData.CurY>Y2-Y1-2-FixSize)
          break;
      }
    }
    else
    {
      if (StackData.CurX==X2-X1-2 && !IsReferencePresent())
        StackData.CurX=0;
      if (--StackData.CurX < 0)
      {
        StartSelection=0;
        StackData.CurX=X2-X1-2;
        StackData.CurY--;
        if (StackData.TopStr+StackData.CurY<0 ||
            CurScreen && StackData.CurY<0)
          break;
      }
    }

    FastShow();
    if (*StackData.SelTopic==0)
      StartSelection=0;
    else
      if (StartSelection)
        *StackData.SelTopic=0;
  }
  DisableOut=FALSE;
  if (*StackData.SelTopic==0)
  {
    StackData.CurX=SaveCurX;
    StackData.CurY=SaveCurY;
    StackData.TopStr=SaveTopStr;
  }
  FastShow();
}

void Help::ReadDocumentsHelp(int TypeIndex)
{
  if(HelpData)
    free(HelpData);
  HelpData=NULL;

  StrCount=0;
  FixCount=1;
  FixSize=2;
  StackData.TopStr=0;
  TopicFound=TRUE;
  StackData.CurX=StackData.CurY=0;
  CtrlColorChar=0;

  char *PtrTitle, *ContentsName;
  char Path[NM],FullFileName[NM],*PtrPath,*Slash;
  char EntryName[512],HelpLine[512],SecondParam[512];

  switch(TypeIndex)
  {
    case HIDX_PLUGINS:
      PtrTitle=MSG(MPluginsHelpTitle);
      ContentsName="PluginContents";
      break;
    case HIDX_DOCUMS:
      PtrTitle=MSG(MDocumentsHelpTitle);
      ContentsName="DocumentContents";
      break;
  }

  AddTitle(PtrTitle);

  /* TODO:
     1. ����� (��� "����������") �� ������ � �������� Documets, ��
        � � ��������
  */

  switch(TypeIndex)
  {
    case HIDX_PLUGINS:
    {
      for (int I=0;I<CtrlObject->Plugins.PluginsCount;I++)
      {
        strcpy(Path,CtrlObject->Plugins.PluginsData[I].ModuleName);
        if ((Slash=strrchr(Path,'\\'))!=NULL)
          *Slash=0;
        FILE *HelpFile=Language::OpenLangFile(Path,HelpFileMask,Opt.HelpLanguage,FullFileName);
        if (HelpFile!=NULL)
        {
          char EntryName[512],HelpLine[512],SecondParam[512];
          if (Language::GetLangParam(HelpFile,ContentsName,EntryName,SecondParam))
          {
            if (*SecondParam)
              sprintf(HelpLine,"   ~%s,%s~@" HelpFormatLink "@",EntryName,SecondParam,Path,"Contents");
            else
              sprintf(HelpLine,"   ~%s~@" HelpFormatLink "@",EntryName,Path,"Contents");
            AddLine(HelpLine);
          }

          fclose(HelpFile);
        }
      }
      break;
    }

    case HIDX_DOCUMS:
    {
#if 0
      // � ��������.
      for (int I=0;I<CtrlObject->Plugins.PluginsCount;I++)
      {
        strcpy(Path,CtrlObject->Plugins.PluginsData[I].ModuleName);
        if ((Slash=strrchr(Path,'\\'))!=NULL)
          *Slash=0;
        FILE *HelpFile=Language::OpenLangFile(Path,HelpFileMask,Opt.HelpLanguage,FullFileName);
        if (HelpFile!=NULL)
        {
          if (Language::GetLangParam(HelpFile,ContentsName,EntryName,SecondParam))
          {
            if (*SecondParam)
              sprintf(HelpLine,"   ~%s,%s~@<%s>%s@",EntryName,SecondParam,FullFileName,"Contents");
            else
              sprintf(HelpLine,"   ~%s~@<%s>%s@",EntryName,FullFileName,"Contents");
            AddLine(HelpLine);
          }

          fclose(HelpFile);
        }
      }

      // � ����������.
      {
        WIN32_FIND_DATA FindData;
        ScanTree ScTree(FALSE,FALSE);
        AddEndSlash(strcpy(Path,FarPath));
        strcat(Path,"Doc");
        ScTree.SetFindPath(Path,HelpFileMask);
        while (ScTree.GetNextName(&FindData,FullFileName))
        {
          if((PtrPath=strrchr(FullFileName,'\\')) != NULL)
            *PtrPath++=0;
          else
            PtrPath=HelpFileMask;
          FILE *HelpFile=Language::OpenLangFile(Path,PtrPath,Opt.HelpLanguage,FullFileName);
          if (HelpFile!=NULL)
          {
            if (Language::GetLangParam(HelpFile,ContentsName,EntryName,SecondParam))
            {
              if (*SecondParam)
                sprintf(HelpLine,"   ~%s,%s~@<%s>%s@",EntryName,SecondParam,FullFileName,"Contents");
              else
                sprintf(HelpLine,"   ~%s~@<%s>%s@",EntryName,FullFileName,"Contents");
_SVS(SysLog("HelpLine=%s",HelpLine));
              AddLine(HelpLine);
            }
            fclose(HelpFile);
          }
        }
      }
#endif
      break;
    }
  }
  /* $ 26.06.2000 IS
   ���������� ����� � ������ �� f1, shift+f2, end (������� ��������� IG)
  */
  AddLine("");
  /* IS $ */
}

// ������������ ������ � ������ ������ ��������
char *Help::MkTopic(int PluginNumber,const char *HelpTopic,char *Topic)
{
  *Topic=0;
  if (HelpTopic && *HelpTopic)
  {
    if (*HelpTopic==':')
      strcpy(Topic,HelpTopic+1);
    else
    {
      if(PluginNumber != -1 && *HelpTopic!=HelpBeginLink)
      {
         sprintf(Topic,HelpFormatLink,
                CtrlObject->Plugins.PluginsData[PluginNumber].ModuleName,
                HelpTopic);
      }
      else
        strncpy(Topic,HelpTopic,511);

      if(*Topic==HelpBeginLink)
      {
        char *Ptr, *Ptr2;
        if((Ptr=strchr(Topic,HelpEndLink)) == NULL)
          *Topic=0;
        else
        {
          if(!Ptr[1]) // ���� ��� ������� ��...
            strcat(Topic,"Contents"); // ... ������ ������� �������� ����.

          /* � ��� ������ ���������...
             ������ ����� ���� :
               "<FullPath>Topic" ��� "<FullModuleName>Topic"
             ��� ������ "FullPath" ���� ������ ������������� ������!
             �.�. �� ������� ��� ��� - ��� ������ ��� ����!
          */
          Ptr2=Ptr-1;
          if(*Ptr2 != '\\') // ��� ��� ������?
          {
            // ������ ������ ��� ������� ��� :-)
            if((Ptr2=strrchr(Topic,'\\')) == NULL) // ��! ����� �����-�� :-(
              *Topic=0;
          }
          if(*Topic)
          {
            /* $ 21.08.2001 KM
              - ������� ���������� ����� � ������ ������ �������,
                � ������� ���� ��� ������ ������ ������������� "/".
            */
            memmove(Ptr2+1,Ptr,strlen(Ptr)+1); //???
            /* KM $ */

            // � ��� ����� ������ ��� �� �������� Help API!
          }
        }
      }
    }
  }
  return *Topic?Topic:NULL;
}


/* $ 28.06.2000 tran
 (NT Console resize)
 resize help*/
void Help::SetScreenPosition()
{
  if (Opt.FullScreenHelp)
  {
    HelpKeyBar.Hide();
    SetPosition(0,0,ScrX,ScrY);
  }
  else
    SetPosition(4,2,ScrX-4,ScrY-2);
  Show();
}
/* tran $ */

/* $ 30.12.2000 SVS
  ������� ������������� KeyBar Labels
*/
void Help::InitKeyBar(void)
{
  char *FHelpKeys[]={MSG(MHelpF1),MSG(MHelpF2),MSG(MHelpF3),MSG(MHelpF4),MSG(MHelpF5),MSG(MHelpF6),MSG(MHelpF7),MSG(MHelpF8),MSG(MHelpF9),MSG(MHelpF10),MSG(MHelpF11),MSG(MHelpF12)};
  char *FHelpShiftKeys[]={MSG(MHelpShiftF1),MSG(MHelpShiftF2),MSG(MHelpShiftF3),MSG(MHelpShiftF4),MSG(MHelpShiftF5),MSG(MHelpShiftF6),MSG(MHelpShiftF7),MSG(MHelpShiftF8),MSG(MHelpShiftF9),MSG(MHelpShiftF10),MSG(MHelpShiftF11),MSG(MHelpShiftF12)};
  char *FHelpAltKeys[]={MSG(MHelpAltF1),MSG(MHelpAltF2),MSG(MHelpAltF3),MSG(MHelpAltF4),MSG(MHelpAltF5),MSG(MHelpAltF6),MSG(MHelpAltF7),MSG(MHelpAltF8),MSG(MHelpAltF9),MSG(MHelpAltF10),MSG(MHelpAltF11),MSG(MHelpAltF12)};
  char *FHelpCtrlKeys[]={MSG(MHelpCtrlF1),MSG(MHelpCtrlF2),MSG(MHelpCtrlF3),MSG(MHelpCtrlF4),MSG(MHelpCtrlF5),MSG(MHelpCtrlF6),MSG(MHelpCtrlF7),MSG(MHelpCtrlF8),MSG(MHelpCtrlF9),MSG(MHelpCtrlF10),MSG(MHelpCtrlF11),MSG(MHelpCtrlF12)};
//  char *FHelpAltShiftKeys[]={MSG(MHelpAltShiftF1),MSG(MHelpAltShiftF2),MSG(MHelpAltShiftF3),MSG(MHelpAltShiftF4),MSG(MHelpAltShiftF5),MSG(MHelpAltShiftF6),MSG(MHelpAltShiftF7),MSG(MHelpAltShiftF8),MSG(MHelpAltShiftF9),MSG(MHelpAltShiftF10),MSG(MHelpAltShiftF11),MSG(MHelpAltShiftF12)};
//  char *FHelpCtrlShiftKeys[]={MSG(MHelpCtrlShiftF1),MSG(MHelpCtrlShiftF2),MSG(MHelpCtrlShiftF3),MSG(MHelpCtrlShiftF4),MSG(MHelpCtrlShiftF5),MSG(MHelpCtrlShiftF6),MSG(MHelpCtrlShiftF7),MSG(MHelpCtrlShiftF8),MSG(MHelpCtrlShiftF9),MSG(MHelpCtrlShiftF10),MSG(MHelpCtrlShiftF11),MSG(MHelpCtrlShiftF12)};
//  char *FHelpCtrlAltKeys[]={MSG(MHelpCtrlAltF1),MSG(MHelpCtrlAltF2),MSG(MHelpCtrlAltF3),MSG(MHelpCtrlAltF4),MSG(MHelpCtrlAltF5),MSG(MHelpCtrlAltF6),MSG(MHelpCtrlAltF7),MSG(MHelpCtrlAltF8),MSG(MHelpCtrlAltF9),MSG(MHelpCtrlAltF10),MSG(MHelpCtrlAltF11),MSG(MHelpCtrlAltF12)};
  char *FHelpAltShiftKeys[]={"","","","","","","","","","","",""};
  char *FHelpCtrlShiftKeys[]={"","","","","","","","","","","",""};
  char *FHelpCtrlAltKeys[]={"","","","","","","","","","","",""};

  HelpKeyBar.Set(FHelpKeys,sizeof(FHelpKeys)/sizeof(FHelpKeys[0]));
  HelpKeyBar.SetShift(FHelpShiftKeys,sizeof(FHelpShiftKeys)/sizeof(FHelpShiftKeys[0]));
  HelpKeyBar.SetAlt(FHelpAltKeys,sizeof(FHelpAltKeys)/sizeof(FHelpAltKeys[0]));
  HelpKeyBar.SetCtrl(FHelpCtrlKeys,sizeof(FHelpCtrlKeys)/sizeof(FHelpCtrlKeys[0]));
  HelpKeyBar.SetCtrlAlt(FHelpCtrlAltKeys,sizeof(FHelpCtrlAltKeys)/sizeof(FHelpCtrlAltKeys[0]));
  HelpKeyBar.SetCtrlShift(FHelpCtrlShiftKeys,sizeof(FHelpCtrlShiftKeys)/sizeof(FHelpCtrlShiftKeys[0]));
  HelpKeyBar.SetAltShift(FHelpAltShiftKeys,sizeof(FHelpAltShiftKeys)/sizeof(FHelpAltShiftKeys[0]));

  SetKeyBar(&HelpKeyBar);
}
/* SVS $ */

/* $ 25.08.2000 SVS
   ������ URL-������... ;-)
   ��� ���� ��� ������... ���?
   ������:
     0 - ��� �� URL ������ (�� ������)
     1 - CreateProcess ������ FALSE
     2 - ��� ��

   ��������� (��������):
     Protocol="mailto"
     URLPath ="mailto:vskirdin@mail.ru?Subject=Reversi"
*/
static int RunURL(char *Protocol, char *URLPath)
{
  int EditCode=0;
  if(Protocol && *Protocol && URLPath && *URLPath && (Opt.HelpURLRules&0xFF))
  {
    char *Buf=(char*)malloc(2048);
    if(Buf)
    {
      HKEY hKey;
      DWORD Disposition, DataSize=250;
      strcpy(Buf,Protocol);
      strcat(Buf,"\\shell\\open\\command");
      if(RegOpenKeyEx(HKEY_CLASSES_ROOT,Buf,0,KEY_READ,&hKey) == ERROR_SUCCESS)
      {
        Disposition=RegQueryValueEx(hKey,"",0,&Disposition,(LPBYTE)Buf,&DataSize);
        ExpandEnvironmentStr(Buf, Buf, 2048);
        RegCloseKey(hKey);
        if(Disposition == ERROR_SUCCESS)
        {
          char *pp=strrchr(Buf,'%');
          if(pp) *pp='\0'; else strcat(Buf," ");

          // ������ ��� ������ � ������ ~~
          pp=URLPath;
          while(*pp && (pp=strstr(pp,"~~")) != NULL)
          {
            memmove(pp,pp+1,strlen(pp+1)+1);
            ++pp;
          }
          // ������ ��� ������ � ������ ##
          pp=URLPath;
          while(*pp && (pp=strstr(pp,"##")) != NULL)
          {
            memmove(pp,pp+1,strlen(pp+1)+1);
            ++pp;
          }

          Disposition=0;
          if(Opt.HelpURLRules == 2 || Opt.HelpURLRules == 2+256)
            Disposition=Message(MSG_WARNING,2,MSG(MHelpTitle),
                        MSG(MHelpActivatorURL),
                        Buf,
                        MSG(MHelpActivatorFormat),
                        URLPath,
                        "\x01",
                        MSG(MHelpActivatorQ),
                        MSG(MYes),MSG(MNo));

          EditCode=2; // ��� Ok!
          if(Disposition == 0)
          {
            /*
              ���� ����� ���������� ������ � ������������ ������
              ���� ��� ����� ���������� - �� ����� ���� ���������!!!!!
            */
            if(Opt.HelpURLRules < 256) // SHELLEXECUTEEX_METHOD
            {
#if 0
              SHELLEXECUTEINFO sei;

              OemToChar(URLPath,Buf);
              memset(&sei,0,sizeof(sei));
              sei.cbSize=sizeof(sei);
              sei.fMask=SEE_MASK_NOCLOSEPROCESS|SEE_MASK_FLAG_DDEWAIT;
              sei.lpFile=RemoveExternalSpaces(Buf);
              sei.nShow=SW_SHOWNORMAL;
              SetFileApisToANSI();
              if(ShellExecuteEx(&sei))
                EditCode=1;
              SetFileApisToOEM();
#else
              OemToChar(URLPath,Buf);
              SetFileApisToANSI();
              EditCode=ShellExecute(0, 0, RemoveExternalSpaces(Buf), 0, 0, SW_SHOWNORMAL)?1:2;
              SetFileApisToOEM();
#endif
            }
            else
            {
              STARTUPINFO si={0};
              PROCESS_INFORMATION pi={0};
              si.cb=sizeof(si);
              strcat(Buf,URLPath);
              OemToChar(Buf,Buf);
              SetFileApisToANSI(); //????
              if(!CreateProcess(NULL,Buf,NULL,NULL,TRUE,0,NULL,NULL,&si,&pi))
                 EditCode=1;
              SetFileApisToOEM(); //????
            }
          }
        }
      }
      free(Buf);
    }
  }
  return EditCode;
}

void Help::OnChangeFocus(int Focus)
{
  if (Focus)
  {
    DisplayObject();
  }
}

void Help::ResizeConsole()
{
  int OldIsNewTopic=IsNewTopic;
  IsNewTopic=FALSE;
  delete TopScreen;
  TopScreen=NULL;
  Hide();
  if (Opt.FullScreenHelp)
  {
    HelpKeyBar.Hide();
    SetPosition(0,0,ScrX,ScrY);
  }
  else
    SetPosition(4,2,ScrX-4,ScrY-2);
  ReadHelp(HelpMask);
  StackData.CurY--; // ��� ���� ������� (����� ���� ����� ���!)
  MoveToReference(1,1);
  IsNewTopic=OldIsNewTopic;
  FrameManager->ImmediateHide();
  FrameManager->RefreshFrame();
}

int Help::FastHide()
{
  return Opt.AllCtrlAltShiftRule & CASR_HELP;
}


/* ------------------------------------------------------------------ */
void CallBackStack::ClearStack()
{
  while(!isEmpty())
    Pop();
}

int CallBackStack::Pop(struct StackHelpData *Dest)
{
  if(!isEmpty())
  {
    ListNode *oldTop = topOfStack;
    topOfStack = topOfStack->Next;
    if(Dest!=NULL)
    {
      strcpy(Dest->HelpTopic,oldTop->HelpTopic);
      strcpy(Dest->HelpPath,oldTop->HelpPath);
      strcpy(Dest->SelTopic,oldTop->SelTopic);
      Dest->Flags=oldTop->Flags;
      Dest->TopStr=oldTop->TopStr;
      Dest->CurX=oldTop->CurX;
      Dest->CurY=oldTop->CurY;
    }
    delete oldTop;
    return TRUE;
  }
  return FALSE;
}

void CallBackStack::Push(const struct StackHelpData *Data)
{
  topOfStack=new ListNode(Data,topOfStack);
}

void CallBackStack::PrintStack(const char *Title)
{
#if defined(SYSLOG)
  int I=0;
  ListNode *Ptr = topOfStack;
  SysLog("Return Stack (%s)",Title);
  SysLog(1);
  while(Ptr)
  {
    SysLog("%03d '%s' '%s'",I++,Ptr->HelpTopic,Ptr->HelpPath);
    Ptr=Ptr->Next;
  }
  SysLog(-1);
#endif
}
#endif // defined(DHELP2)
