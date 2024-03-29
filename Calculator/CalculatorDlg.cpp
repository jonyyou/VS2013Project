
// CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.1415926   //定义PI
typedef long long ll;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NUM0, m_num0);
	DDX_Control(pDX, IDC_NUM1, m_num1);
	DDX_Control(pDX, IDC_NUM2, m_num2);
	DDX_Control(pDX, IDC_NUM3, m_num3);
	DDX_Control(pDX, IDC_NUM4, m_num4);
	DDX_Control(pDX, IDC_NUM5, m_num5);
	DDX_Control(pDX, IDC_NUM6, m_num6);
	DDX_Control(pDX, IDC_NUM7, m_num7);
	DDX_Control(pDX, IDC_NUM8, m_num8);
	DDX_Control(pDX, IDC_NUM9, m_num9);
	//  DDX_Control(pDX, IDC_RESULT, m_result);
	DDX_Control(pDX, IDC_BUTTON1, m_clear);
	DDX_Control(pDX, IDC_BUTTON2, m_backspace);
	DDX_Control(pDX, IDC_cheng, m_cheng);
	DDX_Control(pDX, IDC_chu, m_chu);
	DDX_Control(pDX, IDC_cifang, m_cifang);
	DDX_Control(pDX, IDC_cos, m_cos);
	DDX_Control(pDX, IDC_daoshu, m_daoshu);
	DDX_Control(pDX, IDC_dengyu, m_dengyu);
	DDX_Control(pDX, IDC_dian, m_dian);
	DDX_Control(pDX, IDC_jia, m_jia);
	DDX_Control(pDX, IDC_jian, m_jian);
	DDX_Control(pDX, IDC_jiecheng, m_jiecheng);
	DDX_Control(pDX, IDC_ln, m_ln);
	DDX_Control(pDX, IDC_sin, m_sin);
	DDX_Control(pDX, IDC_sqrt, m_sqrt);
	DDX_Control(pDX, IDC_tan, m_tan);
	//  DDX_Control(pDX, IDC_RESULT, m_result);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_NUM1, &CCalculatorDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM2, &CCalculatorDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM3, &CCalculatorDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_NUM4, &CCalculatorDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM5, &CCalculatorDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM6, &CCalculatorDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM7, &CCalculatorDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM8, &CCalculatorDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM9, &CCalculatorDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_NUM0, &CCalculatorDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_jia, &CCalculatorDlg::OnBnClickedjia)
	ON_BN_CLICKED(IDC_dengyu, &CCalculatorDlg::OnBnClickeddengyu)
	ON_BN_CLICKED(IDC_chu, &CCalculatorDlg::OnBnClickedchu)
	ON_BN_CLICKED(IDC_jian, &CCalculatorDlg::OnBnClickedjian)
	ON_BN_CLICKED(IDC_cheng, &CCalculatorDlg::OnBnClickedcheng)
	ON_BN_CLICKED(IDC_sin, &CCalculatorDlg::OnBnClickedsin)
	ON_BN_CLICKED(IDC_cos, &CCalculatorDlg::OnBnClickedcos)
	ON_BN_CLICKED(IDC_tan, &CCalculatorDlg::OnBnClickedtan)
	ON_BN_CLICKED(IDC_sqrt, &CCalculatorDlg::OnBnClickedsqrt)
	ON_BN_CLICKED(IDC_dian, &CCalculatorDlg::OnBnClickeddian)
	ON_BN_CLICKED(IDC_jiecheng, &CCalculatorDlg::OnBnClickedjiecheng)
	ON_BN_CLICKED(IDC_daoshu, &CCalculatorDlg::OnBnClickeddaoshu)
	ON_BN_CLICKED(IDC_ln, &CCalculatorDlg::OnBnClickedln)
	ON_BN_CLICKED(IDC_cifang, &CCalculatorDlg::OnBnClickedcifang)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO:  在此添加额外的初始化代码



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

ll fac(int n)   //求阶乘的函数
{
	ll result = 1;   //ll表示数据类型long long
	if (n == 0 || n == 1)
		return 1;

	for (int i = n; i > 1; i--)
		result *= i;
	return result;
	
}

ll cifang(int n)
{
	ll result = 1;
	if (n == 0)
		return 1;
	for (int i = 1; i <= n; i++)
		result *= 10;
	return result;
}






void CCalculatorDlg::OnBnClickedNum1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("1"));
}


void CCalculatorDlg::OnBnClickedNum2()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("2"));

}


void CCalculatorDlg::OnBnClickedNum3()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("3"));
}


void CCalculatorDlg::OnBnClickedNum4()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("4"));
}


void CCalculatorDlg::OnBnClickedNum5()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("5"));
}


void CCalculatorDlg::OnBnClickedNum6()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("6"));
}


void CCalculatorDlg::OnBnClickedNum7()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("7"));
}


void CCalculatorDlg::OnBnClickedNum8()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("8"));
}


void CCalculatorDlg::OnBnClickedNum9()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("9"));
}


void CCalculatorDlg::OnBnClickedNum0()
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	SetDlgItemText(IDC_RESULT, s + _T("0"));
}

void CCalculatorDlg::OnBnClickeddian()   //小数点的处理函数
{
	// TODO:  在此添加控件通知处理程序代码
	CString s;
	GetDlgItemText(IDC_RESULT, s);
	if (s.Find('.') == -1)
	{
		SetDlgItemText(IDC_RESULT, s + _T("."));
	}
	

}

///定义全局变量
double num1;  //第一个操作数
double num2;  //第二个操作数
double result;
CString opt; //操作符

void CCalculatorDlg::OnBnClickedjia()   //加号的处理函数
{
	// TODO:  在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_RESULT, cs);
	num1 = _tstof(cs);
	opt = "+";
	SetDlgItemText(IDC_RESULT, _T(""));  //按下加号之后把输入框清空
}

void CCalculatorDlg::OnBnClickedjian()  //减号的处理函数
{
	// TODO:  在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_RESULT, cs);
	num1 = _tstof(cs);
	opt = "-";
	SetDlgItemText(IDC_RESULT, _T(""));  
}

void CCalculatorDlg::OnBnClickedcheng()  //乘号的处理函数
{
	// TODO:  在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_RESULT, cs);
	num1 = _tstof(cs);
	opt = "*";
	SetDlgItemText(IDC_RESULT, _T(""));  
}

void CCalculatorDlg::OnBnClickedchu()   //除号的处理函数
{
	// TODO:  在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_RESULT, cs);
	num1 = _tstof(cs);
	opt = "/";
	SetDlgItemText(IDC_RESULT, _T(""));  
}

void CCalculatorDlg::OnBnClickedsin()  //sin
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "sin";
	SetDlgItemText(IDC_RESULT, _T(""));
}


void CCalculatorDlg::OnBnClickedcos()  //cos
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "cos";
	SetDlgItemText(IDC_RESULT, _T(""));
}


void CCalculatorDlg::OnBnClickedtan()  //tan
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "tan";
	SetDlgItemText(IDC_RESULT, _T(""));
}


void CCalculatorDlg::OnBnClickedsqrt()  //开平方根
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "sqrt";
	SetDlgItemText(IDC_RESULT, _T(""));
}

void CCalculatorDlg::OnBnClickedjiecheng()  //n的阶乘
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "jiecheng";
	SetDlgItemText(IDC_RESULT, _T(""));
}


void CCalculatorDlg::OnBnClickeddaoshu()  //倒数 1/x
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "daoshu";
	SetDlgItemText(IDC_RESULT, _T(""));
}


void CCalculatorDlg::OnBnClickedln()  //求对数ln
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "ln";
	SetDlgItemText(IDC_RESULT, _T(""));
}


void CCalculatorDlg::OnBnClickedcifang()  //10的次方
{
	// TODO:  在此添加控件通知处理程序代码
	opt = "cifang";
	SetDlgItemText(IDC_RESULT, _T(""));
}




void CCalculatorDlg::OnBnClickeddengyu()  //等于号的处理函数， 判断输入的操作码，从而执行相应的操作
{
	// TODO:  在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_RESULT, cs);
	num2 = _tstof(cs);
	
	if (opt.Compare(_T("+")) == 0)  //等于0 表示两个字符串相同
	{
		result = num1 + num2;
	}
	else if (opt.Compare(_T("-")) == 0)
	{
		result = num1 - num2;
	}
	else if (opt.Compare(_T("*")) == 0)
	{
		result = num1 * num2;
	}
	else if (opt.Compare(_T("sin")) == 0)   //输入的是度数，而math.h中的三角函数的形参是弧度，所以需要转换一下
	{
		result = sin(num2* (PI/180));
	}
	else if (opt.Compare(_T("cos")) == 0)
	{		
		result = cos(num2* (PI / 180));
	}
	else if (opt.Compare(_T("tan")) == 0)
	{
		result = tan(num2* (PI / 180));
	}
	else if (opt.Compare(_T("sqrt")) == 0)
	{
		result = sqrt(num2);
	}
	else if (opt.Compare(_T("ln")) == 0)
	{
		result = log(num2);     //math.h 中log函数是求以e为底的ln
	}

	int resultQuZheng = (int)result;  //将result取整
	if (result-resultQuZheng>0)   //如果运算结果是整数则显示整数
		cs.Format(_T("%.6lf"), result);
	else
		cs.Format(_T("%d"), resultQuZheng);  //否则，显示保留六个小数位的浮点数
	SetDlgItemText(IDC_RESULT, cs);


	//特殊情况 单独列出来
	if (opt.Compare(_T("/")) == 0)  //等于0 表示两个字符串相同
	{
		if (num2 == 0.0)
		{
			CString error = _T("除数不能为零");
		}
		else
		{
			result = num1/num2;    
			cs.Format(_T("%.6lf"), result);
			SetDlgItemText(IDC_RESULT, cs);
		}
	}
	else if (opt.Compare(_T("daoshu")) == 0)
	{
		if (num2 == 0.0)
		{
			CString error = _T("除数不能为零");
		}
		else
		{
			result = 1.0 / num2;
			cs.Format(_T("%.6lf"), result);
			SetDlgItemText(IDC_RESULT, cs);
		}
	}
	else if (opt.Compare(_T("jiecheng")) == 0)
	{
		num2 = (int)num2;
		ll result = fac(num2);
		cs.Format(_T("%lld"), result);
		SetDlgItemText(IDC_RESULT, cs);
	}
	else if (opt.Compare(_T("cifang")) == 0)
	{
		num2 = (int)num2;
		ll result = cifang(num2);
		cs.Format(_T("%lld"), result);
		SetDlgItemText(IDC_RESULT, cs);
	}
}


void CCalculatorDlg::OnBnClickedButton1()  //clear 清零按钮
{
	// TODO:  在此添加控件通知处理程序代码
	num1 = 0;
	num2 = 0;
	result = 0;
	opt = _T("");
	SetDlgItemText(IDC_RESULT, _T(""));
}


void CCalculatorDlg::OnBnClickedButton2()  //backspace 退格按钮
{
	// TODO:  在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_RESULT, cs);
	cs.Delete(cs.GetLength() - 1);
	SetDlgItemText(IDC_RESULT, cs);

}









