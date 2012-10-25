#pragma once

#include "MultiDoc.h"


// CMultiView2 form view

class CMultiView2 : public CFormView
{
	DECLARE_DYNCREATE(CMultiView2)

public:
	CMultiView2();           // protected constructor used by dynamic creation
	virtual ~CMultiView2();

public:
	enum { IDD = IDD_MULTIVIEW2 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMultiDoc* GetDocument(void) const;
};

#ifndef _DEBUG  // MultiView.cpp 中的调试版本
inline CMultiDoc* CMultiView::GetDocument() const
{ return reinterpret_cast<CMultiDoc*>(m_pDocument); }
#endif

