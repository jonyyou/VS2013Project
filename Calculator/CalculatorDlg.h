
// CalculatorDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CButton m_num0;
	CButton m_num1;
	CButton m_num2;
	CButton m_num3;
	CButton m_num4;
	CButton m_num5;
	CButton m_num6;
	CButton m_num7;
	CButton m_num8;
	CButton m_num9;
	CButton m_clear;
	CButton m_backspace;
	CButton m_cheng;
	CButton m_chu;
	CButton m_cifang;
	CButton m_cos;
	CButton m_daoshu;
	CButton m_dengyu;
	CButton m_dian;
	CButton m_jia;
	CButton m_jian;
	CButton m_jiecheng;
	CButton m_ln;
	CButton m_sin;
	CButton m_sqrt;
	CButton m_tan;
//	CEdit m_result;
	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedNum2();
	afx_msg void OnBnClickedNum3();
	afx_msg void OnBnClickedNum4();
	afx_msg void OnBnClickedNum5();
	afx_msg void OnBnClickedNum6();
	afx_msg void OnBnClickedNum7();
	afx_msg void OnBnClickedNum8();
	afx_msg void OnBnClickedNum9();
	afx_msg void OnBnClickedNum0();
	afx_msg void OnBnClickedjia();
	afx_msg void OnBnClickeddengyu();
	afx_msg void OnBnClickedchu();
	afx_msg void OnBnClickedjian();
	afx_msg void OnBnClickedcheng();
	afx_msg void OnBnClickedsin();
	afx_msg void OnBnClickedcos();
	afx_msg void OnBnClickedtan();
	afx_msg void OnBnClickedsqrt();
	afx_msg void OnBnClickeddian();
	afx_msg void OnBnClickedjiecheng();
	afx_msg void OnBnClickeddaoshu();
	afx_msg void OnBnClickedln();
	afx_msg void OnBnClickedcifang();
};
