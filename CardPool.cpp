#include <stdlib.h>
#include <time.h>
#include <vector>
#include "CardPool.h"

#define CREATECARD(num,color,name,kind,distance) { this->ALLCARDS[_index]=new Card( _index,num,color,name,kind,distance); _index++; }
#define CREATEROLE(name,sex,country,maxblood) { this->ALLROLES[_index]=new Role( (Role_name)name,sex,country,maxblood); _index++; }

// =====CardPool=====
// 填充指针数组——ALLCARDS[]
int CardPool::full_allcards(){
	int _index = 0;

	// 30杀——————————————————————————
	//d*1=_6_7_8_9_10
	for(int i = 6; i <= 10; i++){
		 CREATECARD( Card_num(i),dianmond,sha,base,0);
	}
	//d*1=_K
	CREATECARD( _K,dianmond,sha,base,0);
	//h*1=_J    h*2=_10
	CREATECARD( _J,heart,sha,base,0);
	CREATECARD( _10,heart,sha,base,0);
	CREATECARD( _10,heart,sha,base,0);
	//c*1=_2_3_4_5_6_7 c*2=_8_9_10_J
	for(int i = 2; i <= 11; i++){
		if(i <= 7){
			CREATECARD( Card_num(i),club,sha,base,0);
		}
		else{
			CREATECARD( Card_num(i),club,sha,base,0);
			CREATECARD( Card_num(i),club,sha,base,0);
		}
	}
	//s*1=_7    s*2=_8_9_10，
	CREATECARD( _7,spade,sha,base,0);
	for(int i = 8; i <= 10; i++){
		CREATECARD( Card_num(i),spade,sha,base,0);
		CREATECARD( Card_num(i),spade,sha,base,0);
	}

	// 24闪
	// h*1=_8_9_J_Q_K		h*2=_2
	CREATECARD( _8,heart,shan,base,0);
	CREATECARD( _9,heart,shan,base,0);
	for(int i = 11; i <= 13; i++){
		CREATECARD( Card_num(i),heart,shan,base,0);
	}
	CREATECARD( _2,heart,shan,base,0);
	CREATECARD( _2,heart,shan,base,0);
	//d*1=_3_4_5_9	   d*2=_2_6_7_8_10
	for(int i = 3; i <= 5; i++){
		CREATECARD( Card_num(i),dianmond,shan,base,0);
	}
	CREATECARD( _9,dianmond,shan,base,0);
	CREATECARD( _2,dianmond,shan,base,0);
	CREATECARD( _2,dianmond,shan,base,0);
	for(int i = 6; i <= 8; i++){
		CREATECARD( Card_num(i),dianmond,shan,base,0);
		CREATECARD( Card_num(i),dianmond,shan,base,0);
	}
	CREATECARD( _10,dianmond,shan,base,0);
	CREATECARD( _10,dianmond,shan,base,0);
	//d*3=_J，
	CREATECARD( _J,dianmond,shan,base,0);
	CREATECARD( _J,dianmond,shan,base,0);
	CREATECARD( _J,dianmond,shan,base,0);

	// 12桃
	// d*1=_2_3_Q
	CREATECARD( _2,dianmond,tao,base,0);
	CREATECARD( _3,dianmond,tao,base,0);
	CREATECARD( _Q,dianmond,tao,base,0);
	// h*1=_3_4_5_7_8_9_Q    h*2=_6
	for(int i = 3; i <= 9; i++){
		if(i == 6){
			CREATECARD( Card_num(i),heart,tao,base,0);
			CREATECARD( Card_num(i),heart,tao,base,0);
		}
		else{
			CREATECARD( Card_num(i),heart,tao,base,0);
		}
	}
	CREATECARD( _Q,heart,tao,base,0);

	// 7无懈可击_Ah_Js_Qdc_Khsc，
	CREATECARD( _A,heart,wxkj,instant_magic,0);
	CREATECARD( _J,spade,wxkj,instant_magic,0);
	CREATECARD( _Q,dianmond,wxkj,instant_magic,0);
	CREATECARD( _Q,club,wxkj,instant_magic,0);
	CREATECARD( _K,heart,wxkj,instant_magic,0);
	CREATECARD( _K,spade,wxkj,instant_magic,0);
	CREATECARD( _K,club,wxkj,instant_magic,0);

	// 6过河拆桥_3sc_4sc_Qhs，
	CREATECARD( _3,spade,ghcq,instant_magic,0);
	CREATECARD( _3,club,ghcq,instant_magic,0);
	CREATECARD( _4,spade,ghcq,instant_magic,0);
	CREATECARD( _4,club,ghcq,instant_magic,0);
	CREATECARD( _Q,heart,ghcq,instant_magic,0);
	CREATECARD( _Q,spade,ghcq,instant_magic,0);

	// 5顺手牵羊_3sd_4sd_Js，
	CREATECARD( _3,spade,ssqy,instant_magic,1);
	CREATECARD( _3,dianmond,ssqy,instant_magic,1);
	CREATECARD( _4,spade,ssqy,instant_magic,1);
	CREATECARD( _4,dianmond,ssqy,instant_magic,1);
	CREATECARD( _J,spade,ssqy,instant_magic,1);

	// 3南蛮入侵_7sc_Ks，
	CREATECARD( _7,spade,nmrq,instant_magic,0);
	CREATECARD( _7,club,nmrq,instant_magic,0);
	CREATECARD( _K,spade,nmrq,instant_magic,0);

	// 1万箭齐发_Ah，
	CREATECARD( _A,heart,wjqf,instant_magic,0);

	// 2借刀杀人_Qc_Kc，
	CREATECARD( _Q,club,jdsr,instant_magic,0);
	CREATECARD( _K,club,jdsr,instant_magic,0);

	// 4无中生有_7h_8h_9h_Jh，
	CREATECARD( _7,heart,wzsy,instant_magic,0);
	CREATECARD( _8,heart,wzsy,instant_magic,0);
	CREATECARD( _9,heart,wzsy,instant_magic,0);
	CREATECARD( _J,heart,wzsy,instant_magic,0);

	// 2五谷丰登_3h_4h，
	CREATECARD( _3,heart,wgfd,instant_magic,0);
	CREATECARD( _4,heart,wgfd,instant_magic,0);

	// 1桃园结义_Ah，
	CREATECARD( _A,heart,tyjy,instant_magic,0);

	// 3决斗_Ascd，
	CREATECARD( _A,spade,jd,instant_magic,0);
	CREATECARD( _A,club,jd,instant_magic,0);
	CREATECARD( _A,dianmond,jd,instant_magic,0);

	// 3乐不思蜀_6hcs，
	CREATECARD( _6,heart,lbss,delayed_magic,0);
	CREATECARD( _6,club,lbss,delayed_magic,0);
	CREATECARD( _6,spade,lbss,delayed_magic,0);

	// 2闪电_As_Qh，
	CREATECARD( _A,spade,sd,delayed_magic,0);
	CREATECARD( _Q,heart,sd,delayed_magic,0);

	// 1诸葛连弩_Ad_Ac，
	CREATECARD( _A,dianmond,zgln,weapon,1);
	CREATECARD( _A,club,zgln,weapon,1);

	// 4方天画戟_Qd，
	CREATECARD( _Q,dianmond,fthj,weapon,4);

	// 3贯石斧_5d，
	CREATECARD( _5,dianmond,gsf,weapon,3);

	// 2寒冰剑_2s，
	CREATECARD( _2,spade,hbj,weapon,2);

	// 2青杠剑_6s，
	CREATECARD( _6,spade,qgj,weapon,2);

	// 3丈八蛇矛_Qs，
	CREATECARD( _Q,spade,zbsm,weapon,3);

	// 5麒麟弓_5h，
	CREATECARD( _5,heart,qlg,weapon,5);

	// 3青龙偃月刀_5s，
	CREATECARD( _5,spade,qlyyd,weapon,3);

	// 2雌雄双股剑_2s，
	CREATECARD( _2,spade,cxsgj,weapon,2);

	// 八卦阵_2s_2c，
	CREATECARD( _2,spade,bgz,shield,0);
	CREATECARD( _2,club,bgz,shield,0);

	// 仁王盾_2c
	CREATECARD( _2,club,rwd,shield,0);

	//-1大宛_Ks，赤兔_5h，紫辛_Kd
	CREATECARD( _K,spade,dw,horse_1,-1);
	CREATECARD( _5,heart,ct,horse_1,-1);
	CREATECARD( _K,dianmond,zx,horse_1,-1);

	// +1的卢_5c，绝影_5s，爪黄飞电_Kh
	CREATECARD( _5,club,dl,horse_2,1);
	CREATECARD( _5,spade,jy,horse_2,1);
	CREATECARD( _K,heart,zhfd,horse_2,1);

	return _index;

}

// 填充指针数组——ALLROLES[]
int CardPool::full_allroles(){
	int _index = 0;

	// 1~7 魏国
	for(int i = 1; i <= 4; i++){
		CREATEROLE(i,Man,Wei,4);
	}
	CREATEROLE(Guojia,Man,Wei,3);
	CREATEROLE(Simayi,Man,Wei,3);
	CREATEROLE(Zhenji,Women,Wei,3);

	// 8~14 蜀国
	for(int i = 8; i <= 12; i++){
		CREATEROLE(i,Man,Shu,4);
	}
	CREATEROLE(Zhugeliang,Man,Shu,3);
	CREATEROLE(Huangyueying,Man,Shu,3);

	// 15~22 吴国
	for(int i = 15; i <= 18; i++){
		CREATEROLE(i,Man,Wu,4);
	}
	CREATEROLE(Zhouyu,Man,Wu,3);
	CREATEROLE(Luxun,Man,Wu,3);
	CREATEROLE(Sunshangxiang,Women,Wu,3);
	CREATEROLE(Daqiao,Women,Wu,3);

	// 23~25 群
	CREATEROLE(Lvbu,Man,Wu,4);
	CREATEROLE(Huatuo,Man,Wu,3);
	CREATEROLE(Diaochan,Women,Wu,3);

	return _index;

}

// =====StackCards=====
int StackCards::random(int _rang,int _increment){
	srand((int)time(0));
	return ( (rand()%_rang)*(rand()%_rang)*_increment+_increment*_increment )%_rang;
}

template<class T>
void StackCards::shuffle(std::vector<T>& _stack){
	int _size = _stack.size();
	std::vector<ICard>::iterator _biter = _stack.begin();
	int i = 0;
	for(std::vector<ICard>::iterator iter = _biter; iter != _stack.end(); iter++,i++){
  	std::vector<ICard>::iterator _riter = _biter+random(_size,i);  //保存临时随机迭代器
		ICard _temp = *iter;
		*iter = *_riter;
		*_riter = _temp;
	}
}

template<class T>
void StackCards::merge(std::vector<T>& _stack1, std::vector<T>& _stack2){
	_stack1.insert(_stack1.begin(), _stack2.begin(), _stack2.end());
}


// =====GamerCards=====
	// 添加手牌，添加后判断手牌是否超过最大限制，不超过返回1，否则返回0
int GamerCards::add_hand_cards(const ICard& _icard){
		hand_cards.push_back(_icard);
		if(hand_cards.size() > MAX_HAND_CARDS )
			return 0;
		return 1;
}

	// 拿去手牌
int GamerCards::erase_hand_cards(const ICard& _icard){
		if(hand_cards.empty())
			return 0;
		for(std::vector<ICard>::iterator iter = hand_cards.begin(); iter != hand_cards.end(); iter++){
			if(*iter == _icard){
				hand_cards.erase(iter);
				return 1;
			}
		}
		return 0;
}

	// 拿去所有手牌
int GamerCards::clear_hand_cards(){
		hand_cards.clear();
		return 1;
}

	// 添加武器牌
int GamerCards::add_weapon_cards(const ICard& _icard){
		if(weapon_cards.size() >= MAX_WEAPON_CARDS){
			weapon_cards.clear();
			weapon_cards.push_back(_icard);
			return 1;
		}

		weapon_cards.push_back(_icard);
		return 1;
}

	// 拿去武器牌
int GamerCards::clear_weapon_cards(){
		weapon_cards.clear();
		return 1;
}

	// 添加盾
int GamerCards::add_shield_cards(const ICard& _icard){
		if(shield_cards.size() >= MAX_SHIELD_CARDS){
			shield_cards.clear();
			shield_cards.push_back(_icard);
			return 1;
		}
		shield_cards.push_back(_icard);
		return 1;
}

	// 拿去盾
int GamerCards::clear_shield_cards(){
		shield_cards.clear();
		return 1;
}

	// 添加＋1马
int GamerCards::add_phorse_cards(const ICard& _icard){
		if(phorse_cards.size() >= MAX_PHORSE_CARDS){
			phorse_cards.clear();
			phorse_cards.push_back(_icard);
			return 1;
		}
		phorse_cards.push_back(_icard);
		return 1;
}

	// 拿去＋1马
int GamerCards::clear_phorse_cards(){
		phorse_cards.clear();
		return 1;
}

	// 添加-1马
int GamerCards::add_shorse_cards(const ICard& _icard){
		if(shorse_cards.size() >= MAX_SHORSE_CARDS){
			shorse_cards.clear();
			shorse_cards.push_back(_icard);
			return 1;
		}
		shorse_cards.push_back(_icard);
		return 1;
}

	// 拿去－1马
int GamerCards::clear_shorse_cards(){
		shorse_cards.clear();
		return 1;
}

// =====GamerBlood=====
	// 改变血量，_change可正可负
void GamerBlood::add_nowblood(short _change){
	nowblood += _change;
}

	// 获得血量
short GamerBlood::get_nowblood(){
	return nowblood;
}

	// 设置血量
void GamerBlood::set_nowblood(short _change){
	nowblood = _change;
}

// =====GamerRoles=====
 // 给玩家增加角色
void GamerRoles::add_role(const IRole& _irole){
	myroles.push_back(_irole);
}

	// 通过索引获得角色信息
const IRole& GamerRoles::get_role_byindex(int _index){
	return myroles[_index];
}
