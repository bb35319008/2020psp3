# 課題3 レポート
学生番号　氏名


## 課題  

以下の2つのアルゴリズムで文字列を検索するプログラムを作成する。  
- 力ずく法
- BM法

1. 使用するデータ  
以下のデータを使用する。ただし、検索対象文字列、検索する文字列は変更しても良い。  
    - StrOriginal: 検索対象データ
    - StrKey: 検索する文字列

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。C言語の標準ライブラリは使用しないこと。  
    (1) ForceSearch: 力ずく法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  

    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

    (2) BMSearch: BM法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  
 
    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

3. 補助関数  
なし

## ソースコードの説明
13: int型の変数 i, text_len, key_len, n, cn, x を宣言し、x に0を代入

15~16: i を0とし、text[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

16: text_len に i を代入

19~20: i を0とし、key[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

20: key_len に i を代入

23~35: i を0とし、i が text_len - key_len 以下の時は以下を繰り返し実行し i に1を加算

24~34: n を0とし、cn が key_len 以下の時は以下を繰り返し実行し n に1を加算

25: cn に i + x を代入

26~30: text[cn] が key[n] と等しいときは以下を実行

27: x に1を加算

28~29: n と key_len が等しいときは以下を実行

29: &text[i+1] を返す

31~32: text[cn] が key[n] と等しくないとき以下を実行

32: ループを抜ける

37: NULL を返す

43: int型の変数 i, text_len, key_len table[256], n, cn, index, x, z を宣言し、z に0を代入

45~47: i を0とし、text[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

46: text_len に i を代入

49~51: i を0とし、key[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

50: key_len に i を代入

53~55: i を0とし、i が 255 以下の時は以下を繰り返し実行し i に1を加算

54: table[i] に key_len + 1 を代入

57~59: i を0とし、key[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

58: table[(unsigned char)key[i]] に key_len - i を代入

61~88: i を key_len とし、i が text_len 以下の時は以下を繰り返し実行し、i に i + index を代入

62~87: cn を i とし、cn が cn - key_len 以上の時は以下を繰り返し実行し cn から1を引く

63: n に key_len - z を代入

64~68: text[cn] が key[n] と等しいとき以下を実行

65: z に1を加算

66~68: z が key_len + 1 と等しいとき以下を実行

67: &text[i - key_len] を返す

69~86: text[cn] が key[n] と等しくないとき以下を実行

70: z に0を代入

71: x に0を代入

72~78: n - x が 0 以上の限り以下を繰り返し実行

73~76: text[cn] が key[n-x] と等しいとき以下を実行

74: index に table[(unsigned char)key[n-x]] を代入

75: ループを抜ける

77: x に1を加算

80~82: text[cn] が key[n-x] が等しいとき以下を実行

81: ループを抜ける

84: index に table[0] を代入

85: ループを抜ける

90: NULL を返す

## 出力結果

```
Force Search. Find keyword at:wind in my hair.
BM Search. Find keyword at:wind in my hair.
```

## 修正履歴
条件で2回break関数を使えるようにし、また、return を途中に入れることで全ての goto関数、ラベルを削除。
一部の変数(x, z)に値を与えて計算がうまくいくように修正。
table[index] を index に修正。
