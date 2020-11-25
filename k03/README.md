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

29: &text[i] を返す

31~32: text[cn] が key[n] と等しくないとき以下を実行

32: x に0を代入

33: ループを抜ける

38: NULL を返す

44: int型の変数 i, text_len, key_len table[256], n, cn, shift, z を宣言し、z に0を代入

46~48: i を0とし、text[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

47: text_len に i を代入

50~52: i を0とし、key[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

51: key_len に i を代入

54~56: i を0とし、i が 255 以下の時は以下を繰り返し実行し i に1を加算

55: table[i] に key_len + 1 を代入

58~60: i を0とし、key[i] が '\0' でない限り以下を繰り返し実行し i に1を加算

59: table[(unsigned char)key[i]] に key_len - i を代入

62~79: i を key_len とし、i が text_len 以下の時は以下を繰り返し実行し、i に i + shift を代入

63~78: cn を i とし、cn が cn - key_len 以上の時は以下を繰り返し実行し cn から1を引く

64: n に key_len - z を代入

65~69: text[cn] が key[n] と等しいとき以下を実行

66: z に1を加算

67~69: z が key_len + 1 と等しいとき以下を実行

68: &text[i - key_len] を返す

70~77: text[cn] が key[n] と等しくないとき以下を実行

71: z に0を代入

72: shift に table[(unsigned char)key[n-x]] を代入

73~75: cn + shift が i 以下の時は以下を実行

74: shift に i + 1 - cn を代入

76: ループを抜ける

81: NULL を返す

## 出力結果

```
Force Search. Find keyword at:wind in my hair.
BM Search. Find keyword at:wind in my hair.
```

## 修正履歴
条件で2回break関数を使えるようにし、また、return を途中に入れることで全ての goto関数、ラベルを削除。
一部の変数(x, z)に値を与えて計算がうまくいくように修正。
table[index] を index に修正。
分かりやすくするためにBM法のずらし量を index から shift に変更。
力ずく法の返り値を &text[i] に修正し、それでも出力がうまくいくように text[cn] が key[n] と等しくないときに x を0にするように修正。
BM法で繰り返し処理を用いて text[cn] と key[n-x] をわざわざ比較する必要はなく、最初のテーブルを作った時点で text[cn] だけでずらし量を求めることが出来るようになっているので繰り返し処理を削除して修正。
ずらし量を table[(unsigned char)text[cn]] に修正し、それを用いて出した比較位置 cn + shift が前の比較位置 i より小さくなり、比較位置が前に戻ることを防ぐために cn + shift が i より小さいときに shift を i + 1 - cn とし、i を i + 1 に出来るように修正。
