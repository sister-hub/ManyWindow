#include "pch.h"
#include "framework.h"
#include "ManyWindow.h"
#include "ManyWindowDlg.h"
#include "afxdialogex.h"
#include <Mmsystem.h>
#include <conio.h>
#include <VersionHelpers.h>
#include <fstream>
using namespace std;
#pragma comment(lib,"winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void On32771();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg void On32778();
	afx_msg void On32780();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CAboutDlg::On32771)
	ON_COMMAND(ID_32773, &CAboutDlg::On32773)
	ON_COMMAND(ID_32774, &CAboutDlg::On32774)
	ON_COMMAND(ID_32775, &CAboutDlg::On32775)
	ON_COMMAND(ID_32776, &CAboutDlg::On32776)
	ON_COMMAND(ID_32777, &CAboutDlg::On32777)
	ON_COMMAND(ID_32778, &CAboutDlg::On32778)
	ON_COMMAND(ID_32780, &CAboutDlg::On32780)
END_MESSAGE_MAP()


// CManyWindowDlg 对话框



CManyWindowDlg::CManyWindowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MANYWINDOW_DIALOG, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManyWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CManyWindowDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CAboutDlg::On32771)
	ON_COMMAND(ID_32773, &CAboutDlg::On32773)
	ON_COMMAND(ID_32774, &CAboutDlg::On32774)
	ON_COMMAND(ID_32775, &CAboutDlg::On32775)
	ON_COMMAND(ID_32776, &CAboutDlg::On32776)
	ON_COMMAND(ID_32777, &CAboutDlg::On32777)
	ON_COMMAND(ID_32778, &CAboutDlg::On32778)
	ON_COMMAND(ID_32780, &CAboutDlg::On32780)
END_MESSAGE_MAP()

CEdit* edit = new CEdit;
// CManyWindowDlg 消息处理程序
BOOL CManyWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	if (!IsWindowsXPSP3OrGreater())
	{
		MessageBox("您的操作系统是Windows xp，请升级至Windows vista以上再使用。");
		exit(0);
	}
	else if (!IsWindowsXPSP2OrGreater())
	{
		MessageBox("您的操作系统是Windows xp sp2，请升级至Windows vista以上再使用。");
		exit(0);
	}
	else if (!IsWindowsXPSP3OrGreater())
	{
		MessageBox("您的操作系统是Windows xp sp3，请升级至Windows vista以上再使用。");		  
		exit(0);
	}
	CFont font;
	font.DeleteObject();
	font.CreatePointFont(220, _T("新宋体"));
	edit->SetFont(&font);//设置字体;
	
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);
	// TODO: 在此添加额外的初始化代码
	m_menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_menu);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CManyWindowDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CManyWindowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CManyWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox("本应用版本：1.0，版权所有：柳问溪 \n这是我送给宝贝柳问溪的3岁礼物");
}


void CAboutDlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
	if (MessageBox("确定要退出ManyWindow吗？", "确认关闭", MB_YESNO) == IDYES)		//确认关闭
	{
		exit(0);
	}
	else
	{
		
		return;
	}
}
void CAboutDlg::On32773()
{
	// TODO: 在此添加命令处理程序代码
	CString FilePath;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCSTR)_TEXT("wav波形音乐文件 (*.wav)|*.wav|所有文件 (*.*)|*.*||"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		FilePath = dlg.GetPathName();
		CString file = "open " + FilePath + " alias wave";
		mciSendString(file.GetBuffer(), 0, 0, 0);
		mciSendString("play wave",0,0,0);
		
	}
	else
	{
		return;
	}
}




void CAboutDlg::On32774()
{
	// TODO: 在此添加命令处理程序代码
	CString FilePath;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCSTR)_TEXT("mp3音乐文件(*.mp3)|*.mp3|所有文件(*.*)|*.*||"),NULL);
	if (dlg.DoModal() == IDOK)
	{
		FilePath = dlg.GetPathName();
		CString File = "open " + FilePath + " alias mp3";
		mciSendString(File.GetBuffer(), 0, 0, 0);
		mciSendString("play mp3", 0, 0, 0);
	}
	else
	{
		return;
	}
}


void CAboutDlg::On32775()
{
	if (!IsWindowsVistaOrGreater())
	{
		MessageBox("您的操作系统是Windows Vista");				 
	}
	else if (!IsWindows7OrGreater())
	{
		MessageBox("您的操作系统是Windows7");			   
	}
	else if (!IsWindows7SP1OrGreater())
	{
		MessageBox("您的操作系统是Windows7 sp1");			 
	}
	else if (!IsWindows8OrGreater())
	{
		MessageBox("您的操作系统是Windows8");		 
	}
	else if(!IsWindows10OrGreater())
	{
		MessageBox("您的操作系统是Windows10");		  
	}
}


void CAboutDlg::On32776()
{
	// TODO: 在此添加命令处理程序代码
	CString filepath;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCSTR)_TEXT("可执行文件(*.exe)|*.exe||"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		filepath = dlg.GetPathName();
		ShellExecute(NULL, "open", filepath.GetBuffer(), NULL, NULL, SW_SHOWNORMAL);
	}
	else
	{
		return;
	}
	
}


void CAboutDlg::On32777()
{
	
	// TODO: 在此添加命令处理程序代码
	CString filepath;
	CFileDialog dlg(TRUE, NULL, NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCSTR)_TEXT("文本文档(*.txt)|*.txt|所有文件(*.*)|*.*||"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		filepath = dlg.GetPathName();
		CString str;
		CFile file;
		file.Open(filepath.GetBuffer(), CFile::modeReadWrite);
		file.Read(str.GetBuffer(file.GetLength()), file.GetLength());
		file.Close();
		edit->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(0, 0, 2000, 2000), this, 1);
		edit->ShowWindow(TRUE);
		edit->SetWindowTextA(str.GetBuffer());
		
	}
	else
	{
		return;
	}
}


void CAboutDlg::On32778()
{
	// TODO: 在此添加命令处理程序代码
	edit->CloseWindow();
}


void CAboutDlg::On32780()
{
	// TODO: 在此添加命令处理程序代码
	CString FilePath;
	CFileDialog dlg(1,0,0,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,(LPCSTR)_TEXT("文本文件(*.*)|(*.*)||"),NULL);
	if (dlg.DoModal() == IDOK)
	{
		FilePath = dlg.GetPathName();
		
	}
	else
	{
		return;
	}
}
