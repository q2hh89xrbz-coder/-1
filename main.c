/* 翌日を求める関数 */
#include <stdio.h>

/* 閏年とそうでない年の月毎の日数を保持 */
int day[2][13] = {
{ 0,31,28,31,30,31,30,31,31,30,31,30,31 },
{ 0,31,29,31,30,31,30,31,31,30,31,30,31 },
};

/*うるう年かどうかの判定*/
int isleap(int y)
{
	if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
	return 1;
	else return 0;
}

void tomorrow(int*y,int*m,int*d)
{
	if(day[isleap(*y)][*m] != *d){
	*d = *d + 1;
	}
	else if(day[isleap(*y)][*m] == *d && *m != 12){
	*d = 1;
	*m = *m +1;
	}
	else{
	*d = 1;
	*m = 1;
	*y = *y + 1;
	}
}

int main(void)
{
	int y, m, d;
	int ay, am, ad;
	int by, bm, bd;

	printf("年："); scanf("%d",&y);
	printf("月："); scanf("%d",&m);
	printf("日："); scanf("%d",&d);

	/* 月の入力チェック */
if(m < 1 || m > 12){
	printf("月の値が不正です\n");
	return 0;
}

/* 日の入力チェック */
if(d < 1 || d > day[isleap(y)][m]){
	printf("日の値が不正です\n");
	return 0;
}
	ay = by = y;
	am = bm = m;
	ad = bd = d;

	tomorrow(&ay, &am, &ad); /* 次の日 */

	printf("次の日：%d年%d月%d日\n", ay, am, ad);

	return (0);

}
