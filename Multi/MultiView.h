
// MultiView.h : CMultiView 类的接口
//

#pragma once

#include "resource.h"
#include "MultiDoc.h"

class CMultiView : public CFormView
{
public: // 仅从序列化创建
	CMultiView();
	DECLARE_DYNCREATE(CMultiView)

public:
	enum{ IDD = IDD_MULTI_FORM };

// 特性
public:
	CMultiDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMultiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MultiView.cpp 中的调试版本
inline CMultiDoc* CMultiView::GetDocument() const
   { return reinterpret_cast<CMultiDoc*>(m_pDocument); }
#endif

