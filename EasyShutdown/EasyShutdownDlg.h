
// EasyShutdownDlg.h : ヘッダー ファイル
//

#pragma once

// CEasyShutdownDlg ダイアログ
class CEasyShutdownDlg : public CDialogEx
{
// コンストラクション
public:
	CEasyShutdownDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EASYSHUTDOWN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32776();
	afx_msg void On32780();
	afx_msg void On32779();
	afx_msg void On32778();
	afx_msg void On32771();
	afx_msg void On32775();
	afx_msg void On32784();
	afx_msg void On32785();
	afx_msg void On32787();
};
