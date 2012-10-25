
// MultiView.cpp : CMultiView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMultiView ����/����

CMultiView::CMultiView()
	: CFormView(CMultiView::IDD)
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CMultiView ���

#ifdef _DEBUG
void CMultiView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMultiView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMultiDoc* CMultiView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiDoc)));
	return (CMultiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiView ��Ϣ�������
