
// MultiView.cpp : CMultiView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Multi.h"
#endif

#include "MultiDoc.h"
#include "MultiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiView

IMPLEMENT_DYNCREATE(CMultiView, CFormView)

BEGIN_MESSAGE_MAP(CMultiView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMultiView 构造/析构

CMultiView::CMultiView()
	: CFormView(CMultiView::IDD)
{
	// TODO: 在此处添加构造代码

}

CMultiView::~CMultiView()
{
}

void CMultiView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMultiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMultiView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CMultiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMultiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMultiView 诊断

#ifdef _DEBUG
void CMultiView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMultiView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMultiDoc* CMultiView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiDoc)));
	return (CMultiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiView 消息处理程序
