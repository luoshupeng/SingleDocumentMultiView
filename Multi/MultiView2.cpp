// MultiView2.cpp : implementation file
//

#include "stdafx.h"
#include "Multi.h"
#include "MultiView2.h"


// CMultiView2

IMPLEMENT_DYNCREATE(CMultiView2, CFormView)

CMultiView2::CMultiView2()
	: CFormView(CMultiView2::IDD)
{

}

CMultiView2::~CMultiView2()
{
}

void CMultiView2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMultiView2, CFormView)
END_MESSAGE_MAP()


// CMultiView2 diagnostics

#ifdef _DEBUG
void CMultiView2::AssertValid() const
{
	CFormView::AssertValid();
}

CMultiDoc* CMultiView2::GetDocument(void) const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiDoc)));
	return (CMultiDoc*)m_pDocument;
}

#ifndef _WIN32_WCE
void CMultiView2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMultiView2 message handlers


