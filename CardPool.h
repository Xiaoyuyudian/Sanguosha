#ifndef CARDPOOL_H
#define CARDPOOL_H

#include <vector>
#include "Card.h"
#include "Role.h"
#include "Default.h"

#define MAX_ALL_CARDS 124
#define MAX_ALL_ROLES 25


#define MAX_HAND_CARDS 50
#define MAX_WEAPON_CARDS 1
#define MAX_SHIELD_CARDS 1
#define MAX_PHORSE_CARDS 1
#define MAX_SHORSE_CARDS 1

#define MAX_GAMER_ROLES 2

// 牌池
class CardPool{
	public:
	Card* ALLCARDS[MAX_ALL_CARDS];
	Role* ALLROLES[MAX_ALL_ROLES];

	int full_allcards();
	int full_allroles();

};

// 牌堆
class StackCards{
	public:
	std::vector<ICard> positive_card_stack; // 正面牌堆
	std::vector<ICard> negative_card_stack; // 反面牌堆

	std::vector<IRole> positive_role_stack; // 正面牌堆
	std::vector<IRole> negative_role_stack; // 反面牌堆

	int random(int _rang,int _increment); // 产生洗牌随机数

	template<class T>
	void shuffle(std::vector<T>& _stack); // 洗牌堆_stack

	template<class T>
	void merge(std::vector<T>& _stack1,std::vector<T>& _stack2); // 合并两个牌堆
};

// 拥有牌
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

// 拥有血量
class GamerBlood{
	private:
	short nowblood;

	public:
	// 改变血量，_change可正可负
	void add_nowblood(short _change);

	// 获得血量
	short get_nowblood();

	// 设置血量
	void set_nowblood(short _change);
};

// 拥有角色
class GamerRoles{
	private:
		// 玩家拥有的角色
	std::vector<IRole> myroles;

	public:
		// 给玩家增加角色
	void add_role(const IRole& _irole);

		// 通过索引获得角色信息
	const IRole& get_role_byindex(int _index);


};



#endif
