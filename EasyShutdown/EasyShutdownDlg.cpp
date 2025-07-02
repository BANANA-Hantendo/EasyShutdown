
// EasyShutdownDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "EasyShutdown.h"
#include "EasyShutdownDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include <winuser.h>
#include <fstream>
#include <chrono>
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool check = true;

// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEasyShutdownDlg ダイアログ



CEasyShutdownDlg::CEasyShutdownDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EASYSHUTDOWN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEasyShutdownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEasyShutdownDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CEasyShutdownDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CEasyShutdownDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEasyShutdownDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CEasyShutdownDlg::OnBnClickedButton3)
	ON_COMMAND(ID_32772, &CEasyShutdownDlg::On32772)
	ON_COMMAND(ID_32773, &CEasyShutdownDlg::On32773)
	ON_COMMAND(ID_32774, &CEasyShutdownDlg::On32774)
	ON_COMMAND(ID_32776, &CEasyShutdownDlg::On32776)
	ON_COMMAND(ID_32780, &CEasyShutdownDlg::On32780)
	ON_COMMAND(ID_32779, &CEasyShutdownDlg::On32779)
	ON_COMMAND(ID_32778, &CEasyShutdownDlg::On32778)
	ON_COMMAND(ID_32771, &CEasyShutdownDlg::On32771)
	ON_COMMAND(ID_32775, &CEasyShutdownDlg::On32775)
	ON_COMMAND(ID_32784, &CEasyShutdownDlg::On32784)
	ON_COMMAND(ID_32785, &CEasyShutdownDlg::On32785)
	ON_COMMAND(ID_32787, &CEasyShutdownDlg::On32787)
END_MESSAGE_MAP()


// CEasyShutdownDlg メッセージ ハンドラー

BOOL CEasyShutdownDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CEasyShutdownDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CEasyShutdownDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CEasyShutdownDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEasyShutdownDlg::OnBnClickedButton1()
{
	if (check = false) {
		system("shutdown /s /t 0");
	} else if (check = true) {
		system("shutdown /s /f /t 0");
	}
}

void CEasyShutdownDlg::OnBnClickedCheck1()
{
	if (check = false) {
		check = true;
	} else if (check = true) {
		check = false;
	}
}

void CEasyShutdownDlg::OnBnClickedButton2()
{
	if (check = false) {
		system("shutdown /r /t 0");
	}
	else if (check = true) {
		system("shutdown /r /f /t 0");
	}
}

void CEasyShutdownDlg::OnBnClickedButton3()
{
	system("shutdown /h");
}

void CEasyShutdownDlg::On32772()
{
	system("shutdown /s /t 0");
}

void CEasyShutdownDlg::On32773()
{
	system("shutdown /r /t 0");
}

void CEasyShutdownDlg::On32774()
{
	system("shutdown /h");
}

void CEasyShutdownDlg::On32776()
{
	system("shutdown /s /f /t 0");
}

void CEasyShutdownDlg::On32780()
{
	system("shutdown /r /f /t 0");
}

void CEasyShutdownDlg::On32779()
{
	system("shutdown /r /o /f /t 0");
}

void CEasyShutdownDlg::On32778()
{
	system("shutdown /h /f");
}

void CEasyShutdownDlg::On32771()
{
	exit(0);
}

void CEasyShutdownDlg::On32775()
{
	CDialog aboutDlg(IDD_ABOUTBOX);
	INT_PTR nRet = -1;
	nRet = aboutDlg.DoModal();
	switch (nRet)
	{
	case -1:
		AfxMessageBox(_T("ダイアログの作成に失敗しました。\n修正しやがれコノヤロー！"));
		break;
	case IDABORT:
		// Do something
		break;
	case IDOK:
		// Do something
		break;
	case IDCANCEL:
		// Do something
		break;
	default:
		// Do something
		break;
	}
}


void CEasyShutdownDlg::On32784()
{
	system("explorer .\\");
}

void CEasyShutdownDlg::On32785()
{
	ShellExecute(NULL, _T("open"), _T("..\\UPDATE.TXT"), NULL, NULL, SW_SHOWDEFAULT);
}

void CEasyShutdownDlg::On32787()
{
}

