
// EasyShutdown.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル

// CEasyShutdownApp:
// このクラスの実装については、EasyShutdown.cpp を参照してください
//

class CEasyShutdownApp : public CWinApp
{
public:
	CEasyShutdownApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CEasyShutdownApp theApp;
