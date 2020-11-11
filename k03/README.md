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
13: int型の変数 i, text_len, key_len, n, cn, x を宣言

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

29: ラベル END にジャンプ

31~32: text[cn] が key[n] と等しくないとき以下を実行

32: ループを抜ける

37: NULL を返す

39~40: ラベル END。&text[i+1] を返す

46: int型の変数 i, text_len, key_len table[256], n, cn, index, x, z を宣言

48~49: i を0とし、text[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

49: text_len に i を代入

52~53: i を0とし、key[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

53: key_len に i を代入

56~57: i を0とし、i が 255 以下の時は以下を繰り返し実行し i に1を加算

57: table[i] に key_len + 1 を代入

60~61: i を0とし、key[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

61: table[(unsigned char)key[i]] に key_len - i を代入

64~90: i を key_len とし、i が text_len 以下の時は以下を繰り返し実行し、i に i + table[index] を代入

65~89: cn を i とし、cn が cn - key_len 以上の時は以下を繰り返し実行し cn から1を引く

66: n に key_len - z を代入

67~71: text[cn] が key[n] と等しいとき以下を実行

68: z に1を加算

69~71: z が key_len + 1 と等しいとき以下を実行

70: ラベル END にジャンプ

72~88: text[cn] が key[n] と等しくないとき以下を実行

73: z に0を代入

74: x に0を代入

75~81: n - x が 0 以上の限り以下を繰り返し実行

76~79: text[cn] が key[n-x] と等しいとき以下を実行

77: index に table[(unsigned char)key[n-x]] を代入

78: ラベル SKIP にジャンプ

80: x に1を加算

83: index に table[0] を代入

84: ループを抜ける

86~87: ラベル SKIP。ループを抜ける

92: NULL を返す

94~95: ラベル END。&text[i - key_len] を返す

## 出力結果

```
Force Search. Find keyword at:wind in my hair.
BM Search. Find keyword at:wind in my hair.
```

## 修正履歴

