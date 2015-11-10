#include<stdlib.h>
#include<time.h>
#include<vector>
#include<iostream>

#define MAX_ALL_CARDS 124

#define MAX_HAND_CARDS 50
#define MAX_WEAPON_CARDS 1
#define MAX_SHIELD_CARDS 1
#define MAX_PHORSE_CARDS 1
#define MAX_SHORSE_CARDS 1

#define CREATECARD(a,b,c,d,e) this->ALLCARDS[_index++]=new Card( a,b,c,d,e)


template<class T,class G>
class IPtr {
	friend G;
	private:
	T* ptr;
	size_t usecount;
	IPtr(T* _ptr):ptr(_ptr),usecount(1){}
	~IPtr(){delete ptr;}
};

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

//牌类
class Card{

	public:
	Card_num num;
	Card_color color;
	Card_name name;
	Card_kind kind;
	short distance;

	public:
	Card(Card_num _num,
			Card_color _color,
			Card_name _name,
			Card_kind _kind,
			short _distance) : num(_num),
						color(_color),
						name(_name),
						kind(_kind),
						distance(_distance){ }

	void show();
	//void change();
};

//Card的智能指针类
class ICard{

	private:
	void destroyptr(){ if( --iptr->usecount == 0 ) delete iptr; }

	public:
	IPtr<Card,ICard>* iptr;
	
	ICard(Card* _ptr_card):iptr(new IPtr<Card,ICard>(_ptr_card)){ }
	ICard(const ICard& _icard):iptr(_icard.iptr){ ++iptr->usecount; }
	~ICard(){ destroyptr(); }

	ICard& operator=(const ICard&);
	bool operator==(const ICard&);
	Card& operator*(){
		return *(iptr->ptr);
	}
	Card* operator->(){
		return iptr->ptr;
	}
	//void show();
};

class GameCard{
	private:
	std::vector<ICard> cardlist;
	int random(int,int);

	public:
	GameCard();
	void show();
	void shuffle();
};

void Card::show(){
	std::cout<<num<<"    ";
}

/*void Card::change(){
	num = _A;
}*/

ICard& ICard::operator=(const ICard& _icard){
	++_icard.iptr->usecount;
	destroyptr();
	iptr = _icard.iptr;
	return *this;
}

bool ICard::operator == (const ICard& _icard){
	if(iptr->ptr->num == _icard.iptr->ptr->num
		 || iptr->ptr->color == _icard.iptr->ptr->color
		 || iptr->ptr->name ==_icard.iptr->ptr->name)
		return true;
	return false;
}

/*void ICard::show(){
	    std::cout<<iptr->usecount<<std::endl;
}*/

GameCard::GameCard(){
	//杀d*1=_6_7_8_9_10
	for(int i = 6; i <= 10; i++){
		cardlist.push_back( *( new ICard( new Card( Card_num(i),dianmond,sha,base,0) ) ) );
	}
	//d*1=_K
	cardlist.push_back( *( new ICard( new Card( _K,dianmond,sha,base,0) ) ) );
	//c*1=_2_3_4_5_6_7
	for(int i = 2; i <= 7; i++){
		cardlist.push_back( *( new ICard( new Card( Card_num(i),club,sha,base,0) ) ) );
	}
}

void GameCard::show(){
	for(std::vector<ICard>::iterator iter = cardlist.begin(); iter != cardlist.end(); iter++){
		(**iter).show();
	}
}

int GameCard::random(int _rang,int _increment){
    srand((int)time(0));
	return ( (rand()%_rang)*(rand()%_rang)*_increment+_increment*_increment )%_rang;
}

void GameCard::shuffle(){
    int _size = cardlist.size();
	std::vector<ICard>::iterator _biter = cardlist.begin();
	int i = 0;
	std::cout<<std::endl;
	for(std::vector<ICard>::iterator iter = _biter; iter != cardlist.end(); iter++,i++){
        std::vector<ICard>::iterator _riter = _biter+random(_size,i);  //保存临时随机迭代器
		ICard _temp = *iter;
		*iter = *_riter;
		*_riter = _temp;
	}
}

class GamerCards{
	private:
	std::vector<ICard> hand_cards; // 手牌
	std::vector<ICard> weapon_cards; // 武器
	std::vector<ICard> shield_cards; // 盾
	std::vector<ICard> phorse_cards; // ＋1马
	std::vector<ICard> shorse_cards; // －1马
	std::vector<ICard> judge_cards; // 判定牌
	
	public:
	
	// 添加手牌，添加后判断手牌是否超过最大限制，不超过返回1，否则返回0
	int add_hand_cards(const ICard& _icard);
	
	// 拿去手牌
	int erase_hand_cards(const ICard& _icard);
	
	// 拿去所有手牌
	int clear_hand_cards();
	
	// 添加武器牌
	int add_weapon_cards(const ICard& _icard);
	
	// 拿去武器牌
	int clear_weapon_cards();
	
	// 添加盾
	int add_shield_cards(const ICard& _icard);
	
	// 拿去盾
	int clear_shield_cards();
	
	// 添加＋1马
	int add_phorse_cards(const ICard& _icard);
	
	// 拿去＋1马
	int clear_phorse_cards();
	
	// 添加-1马
	int add_shorse_cards(const ICard& _icard);
	
	// 拿去－1马
	int clear_shorse_cards();
	
};


class StackCards{
	public:
	std::vector<ICard> positive_stack; // 正面牌堆
	std::vector<ICard> negative_stack; // 反面牌堆
};

class CardPool{
	public: Card* ALLCARDS[MAX_ALL_CARDS];
	public: int full_allcards();
};

// 所有牌的指针数组
/*extern Card* ALLCARDS[MAX_ALL_CARDS];

// 填充指针数组——ALLCARDS[]
int full_allcards();*/

// GamerCards

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

int main(){
	/*GameCard start;
	start.show();
	std::cout<<std::endl<<"================"<<std::endl;
	start.shuffle();
	start.show();
	std::cout<<std::endl;*/
	CardPool cardpool;
	int all = cardpool.full_allcards();
	std::cout<<"all count : "<<all<<std::endl;
	for(int i = 0; i < MAX_ALL_CARDS; i++){
		cardpool.ALLCARDS[i]->show();
		if(i%10 == 0)
			std::cout<<std::endl;
	}
	
	
}
