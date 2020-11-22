
#ifndef __YX23F01CB_GeneralKey_Touch_Lib_H__
#define __YX23F01CB_GeneralKey_Touch_Lib_H__

//===================================================================================================
extern void CTK_Init(void);			    //调用此程序前必须先打开总中断总开关（EA=1），因为CTK初始化时，需要CTK中断配合
extern void CTK_ISR_Handle(void);       //此函数必须在CTK中断入口中调用
extern void Touch_Signal_Handle(void);  //建议扫描完成一轮后，调用一次
extern void Scan_Pause(void);           //CTK扫描暂停
extern void Scan_Continue(void);        //CTK扫描继续
extern void BaseLineReset(void);        //复位所有通道基线

//===================================================================================================
extern bit  OneCycleScanDone;           //扫描一轮置位一次，一轮时间 ≈ 单个通道扫描时间 * 开启的检测通道个数
extern ux16 TouchKeyFlag;               //按键响应标志，每1BIT 对应一个通道，BIT对应位与HCTouchLib_TK_CH_MASK相对应
extern ux16	XDATA_ConfirmLongTouchTime;//按键最长有效时间计数值
extern ux16	XDATA_THRESHOLD_NOISE_TIME; //阈值噪声更新计数值
extern ux8	XDATA_THRESHOLD_RATIO;      //手指阈值比例
extern ux8	XDATA_FineTuning;           //噪声桶微调步进

extern uc8  TOUCH_LIB_VERSION[];       //触摸库版本编号

#endif /*__YX23F01CB_GeneralKey_Touch_Lib_H__*/
