from openai import OpenAI

#APIを使うkeyを入力します。これは絶対にwebページなどで公開してはいけません。
import os
client = OpenAI(api_key="")


a=input("今の気分を入力")
b=input("今なりたい気分")
c=input("今見たいジャンルを入力")
d=input("最近ハマっていること、ものを入力")
e=input("興味のあること、ものを入力")
f=input("どのくらいの時間で見終えたいか（何分、何クール）入力")
g=input("一番アニメに求めている要素を入力")


question = a+b+c+d+e+f+g+"に合うアニメを教えて"

#ここがAPIです----------------------------
response = client.chat.completions.create(
    model="gpt-4o-mini",
    messages=[ {"role": "system", "content": "あなたはアニメに詳しいユーザー嗜好分析AIです。"},
        {"role": "user", "content": question}]
)
#---------------------------------------

print("AIの答え：", response.choices[0].message.content)

