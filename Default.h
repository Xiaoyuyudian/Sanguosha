#ifndef DEFAULT_H
#define DEFAULT_H

enum Card_num{_A = 1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_J,_Q,_K};

enum Card_color{
		heart, //红桃
		spade, //黑桃
		dianmond, //方块
		club //梅花
};

enum Card_kind{
		base,
		instant_magic,
		delayed_magic,
		weapon,
		shield,
		horse_1, //-1
		horse_2, //+1
		ability
};

enum Card_name{
		sha,shan,tao, //66
		//30杀 d*1=_6_7_8_9_10_K
		     //h*1=_J    h*2=_10
			 //c*1=_2_3_4_5_6_7    c*2=_8_9_10_J
			 //s*1=_7    s*2=_8_9_10，

		//24闪 h*1=_8_9_J_Q_K		h*2=_2
		     //d*1=_3_4_5_9	   d*2=_2_6_7_8_10
			 //d*3=_J，

		//12桃 d*1=_2_3_Q    h*1=_3_4_5_7_8_9_Q    h*2=_6
		wxkj,ghcq,ssqy,nmrq,wjqf,jdsr,wzsy,wgfd,tyjy,jd, //34
		//7无懈可击_Ah_Js_Qdc_Khsc，
		//6过河拆桥_3sc_4sc_Qhs，
		//5顺手牵羊_3sd_4sd_Js，
		//3南蛮入侵_7sc_Ks，
		//1万箭齐发_Ah，
		//2借刀杀人_Qc_Kc，
		//4无中生有_7h_8h_9h_Jh，
		//2五谷丰登_3h_4h，
		//1桃园结义_Ah，
		//3决斗_Ascd，
		lbss,sd, //5
		//3乐不思蜀_6hcs，
		//2闪电_As_Qh，
		zgln,fthj,gsf,hbj,qgj,zbsm,qlg,qlyyd,cxsgj, //10
		//1诸葛连弩_Ad_Ac，
		//4方天画戟_Qd，
		//3贯石斧_5d，
		//2寒冰剑_2s，
		//2青杠剑_6s，
		//3丈八蛇矛_Qs，
		//5麒麟弓_5h，
		//3青龙偃月刀_5s，
		//2雌雄双股剑_2s，
		bgz,rwd, //八卦阵_2s_2c，仁王盾_2c
		dw,ct,zx, //-1大宛_Ks，赤兔_5h，紫辛_Kd
		dl,jy,zhfd, //+1的卢_5c，绝影_5s，爪黄飞电_Kh
};

enum Role_name{
		// 0 裁裁
		REFEREE,

		// 1~7 魏国
		Caocao,Zhangliao,Xuzhu,Xiahoudun,Guojia,Simayi,Zhenji, // 曹操，张辽，许褚，夏侯惇，郭嘉，司马懿，甄姬

		// 8~14 蜀国
		Liubei,Zhangfei,Zhaoyun,Guanyu,Machao,Zhugeliang,Huangyueying, // 刘备，张飞，赵云，关羽，马超，诸葛亮，黄月英

		// 15~22 吴国
		Sunquan,Huanggai,Ganning,Lvmeng,Zhouyu,Luxun,Sunshangxiang,Daqiao, // 孙权，黄盖，甘宁，吕蒙，周瑜，陆逊，孙尚香，大乔

		// 23~25 群
		Lvbu,Huatuo,Diaochan, // 吕布，华佗，貂蝉


};

enum Role_sex{
	Man,Women, // 男，女
};

enum Role_country{
	Wei,Shu,Wu,Qun, // 魏国，蜀国，吴国，群
};

enum Role_ability{


	// 1～7 魏国
	Caocao_JianXiong,Caocao_HuJia, // 曹操——奸雄、护驾
	Zhangliao_TuXi, // 张辽——突袭
	XuZhu_LuoYi, // 许褚——裸衣
	Xiahoudun_GangLie, // 夏侯惇——刚烈
	Guojia_TianDu,Guojia_YiJi, // 郭嘉——天妒、遗计
	Simayi_FanKui,Simayi_GuiCai, // 司马懿——反馈、鬼才
	Zhenji_QingGuo,Zhenji_LuoShen, // 甄姬——倾国、洛神

	// 8~14 蜀国
	Liubei_RenDe,Liubei_JiJiang, // 刘备——仁德、激将
	Zhangfei_PaoXiao, // 张飞——咆哮
	Zhaoyun_LongDan, // 赵云——龙胆
	Guanyu_WuSheng, // 关羽——武圣
	Machao_MaShu,Machao_TieJi, // 马超——马术、铁骑
	Zhugeliang_GuanXing,Zhugeliang_KongCheng, // 诸葛亮——观星、空城
	Huangyueying_JiZhi,Huangyueying_QiCai, // 黄月英——集智、奇才

	// 15~22 吴国
	Sunquan_ZhiHeng,Sunquan_JiuYuan, // 孙权——制衡、救援
	Huanggai_KuRou, // 黄盖——苦肉
	Ganning_QiXi, // 甘宁——奇袭
	Lvmeng_KeJi, // 吕蒙——克己
	Zhouyu_YingZi,Zhouyu_FanJian, // 周瑜——英姿、反间
	Luxun_QianXun,Luxun_LianYing, // 陆逊——谦逊、连营
	Sunshangxiang_JieYin,Sunshangxiang_XiaoJi, // 孙尚香——结姻、枭姬
	Daqiao_GuoSe,Daqiao_LiuLi, // 大乔——国色、流离

	// 23~25 群
	Lvbu_WuShuang, // 吕布——无双
	Huatuo_JiJiu,Huatuo_QingNang, // 华佗——急救、青囊
	Diaochan_LiJian,Diaochan_BiYue, // 貂蝉——离间、闭月

	//

};

enum Gamer_position{
	ZhuGong,ZhongChen,FanZei,NeiJian, // 主公，忠臣，反贼，内奸
};


/*enum Do_name{
		sha,shan,tao,jiu,
		//30杀 d*1=_6_7_8_9_10_K
		     //h*1=_J    h*2=_10
			 //c*1=_2_3_4_5_6_7    c*2=_8_9_10_J
			 //s*1=_7    s*2=_8_9_10，

		//24闪 h*1=_8_9_J_Q_K		h*2=_2
		     //d*1=_3_4_5_9	   d*2=_2_6_7_8_10
			 //d*3=_J，

		//12桃 d*1=_2_3_Q    h*1=_3_4_5_7_8_9_Q    h*2=_6
		wxkj,ghcq,ssqy,nmrq,wjqf,jdsr,wzsy,wgfd,tyjy,jd,
		//7无懈可击_Ah_Js_Qdc_Khsc，
		//6过河拆桥_3sc_4sc_Qhs，
		//5顺手牵羊_3sd_4sd_Js，
		//3南蛮入侵_7sc_Ks，
		//1万箭齐发_Ah，
		//2借刀杀人_Qc_Kc，
		//4无中生有_7h_8h_9h_Jh，
		//2五谷丰登_3h_4h，
		//1桃园结义_Ah，
		//3决斗_Ascd，
		lbss,sd,blcd,
		//3乐不思蜀_6hcs，
		//2闪电_As_Qh，
		zgln,fthj,gsf,hbj,qgj,zbsm,qlg,qlyyd,cxsgj,
		//1诸葛连弩_Ad_Ac，
		//4方天画戟_Qd，
		//3贯石斧_5d，
		//2寒冰剑_2s，
		//2青杠剑_6s，
		//3丈八蛇矛_Qs，
		//5麒麟弓_5h，
		//3青龙偃月刀_5s，
		//2雌雄双股剑_2s，
		bgz,rwd, //八卦阵_2s_2c，仁王盾_2c
		dw,ct,zx, //大宛_Ks，赤兔_5h，紫辛_Kd
		dl,jy,zhfd, //的卢_5c，绝影_5s，爪黄飞电_Kh

		//裁判功能
		Round_Start,Round_End, // 回合开始，回合结束
		Take_Cards,Give_Cards, // 要牌，给牌
		Reduce_Blood,Add_blood, // 扣血，加血

		// 技能
		jieyin,xiaoji, // 孙尚香_结姻_枭姬
		jizhi,qicai, // 黄月英_集智_奇才
};*/

#endif
