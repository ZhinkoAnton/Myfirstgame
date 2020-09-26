
#include "SameGame.h"
#include "OptionDialog.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(COptionDialog, CDialog)

COptionDialog::COptionDialog(bool bRowColumn, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_OPTIONS, pParent)
	, m_nValue1(0)
	, m_nValue2(0)
	, m_bRowColumnDialog(bRowColumn)
{

}

COptionDialog::~COptionDialog()
{
}

void COptionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TEXT_1, m_ctrlStaticText1);
	DDX_Control(pDX, IDC_STATIC_TEXT_2, m_ctrlStaticText2);
	DDX_Text(pDX, IDC_EDIT_VALUE_1, m_nValue1);
	DDX_Text(pDX, IDC_EDIT_VALUE_2, m_nValue2);
}


BEGIN_MESSAGE_MAP(COptionDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_DEFAULTS, &COptionDialog::OnBnClickedButtonDefaults)
END_MESSAGE_MAP()


// Обработчики сообщений COptionDialog


void COptionDialog::OnBnClickedButtonDefaults()
{
	// Отдельно рассматриваем два варианта
	if (m_bRowColumnDialog)
		m_nValue1 = m_nValue2 = 15; // 15x15 размер доски
	else
		m_nValue1 = m_nValue2 = 35; // 35x35 размер блоков
		// Обновляем параметры элементов до новых значений
	UpdateData(false);
}