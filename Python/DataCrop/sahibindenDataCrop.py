import pandas as pd
import requests
from bs4 import BeautifulSoup 


ozellikler = []
years = []
models = []
km = []
color = []
prices = []

headers = {"User-Agent":"personal-user-agent"}
page =requests.get("https://www.sahibinden.com/bmw-5-serisi-520d?pagingOffset=450&pagingSize=50",headers = headers)
soup = BeautifulSoup(page.content, 'html.parser')
print(page.status_code)

ozellik = soup.find_all("td", attrs = {"class":"searchResultsAttributeValue"})
#Gerekli kütüphaneler.
import pandas as pd
import requests
from bs4 import BeautifulSoup 

#Çektiğim verileri bu listelerde tutuyorum.
ozellikler = []
years = []
models = []
km = []
color = []
prices = []

 #User agent sayesinde siteye bot olmadığımızı tanıtıyoruz.
headers = {"User-Agent":"personal-user-agent"}
# Veri çekeceğimiz sitenin url'si
page =requests.get("https://www.sahibinden.com/bmw-5-serisi-520d?pagingOffset=450&pagingSize=50",headers = headers) 
# Beatiful ile site içeriğini html formatında parse layarak çekiyoruz.
soup = BeautifulSoup(page.content, 'html.parser')
# Sayfaya bağlandıık mı bağalanamadık mı onu görüyoruz.
print(page.status_code) 
 # Çektiğim sitede 3 adet özellik 1 td içerisindeydi bunların hepsini çektim.
ozellik = soup.find_all("td", attrs = {"class":"searchResultsAttributeValue"})
# Model bölümünü çektim.
model = soup.find_all("td", attrs = {"class":"searchResultsTagAttributeValue"}) 
#Fiyat bölümünü çektim.
fiyat = soup.find_all("td", attrs={"class":"searchResultsPriceValue"}) 
# Fiyatları prices listine atıyor.
for price in fiyat: 
    prices.append(price.text)
# Çekilen ozellikleri text kısmını alıp ozellikler kısmına atıyor.
for tum in ozellik: 
    ozellikler.append(tum.text)
    print(tum.text)
# Modelleri alıp models listesine atıyor.
for name in model: 
    print(name.text)  
    models.append(name.text)
# Bir sayfada 50 satır bu satırların hepsinin içieriside de 3 adet stün aynı td içinde olduğu için hepsini 1 tane listeye atamak zorunda kaldım.
for i in range(len(ozellik)):  
    if i%3 == 0: # bunları da burada ayıkladım. 3 e bölümünden kalan durumuna göre.
        years.append(ozellik[i].text)# burası yılların atandığı.
    elif i % 3 ==1:
        km.append(ozellik[i].text)# burası km lerin atandığı.
    elif i % 3 == 2:
        color.append(ozellik[i].text)# burası da renklerin atandığı kısım.

#hepsini bir check etmek için yazdırdım.
print("Ozellik:",len(ozellik))
print("Modeller:",len(models))
print("yıllar:",len(years))
print("KM:",len(km))
print("RENKLER:",len(color))

#bu bölüm excel'e yazdırdığım kısım. Bir excel sayfasının içerisine soldan sağa doğru belirtilen başlıklar altında yazdırdım.
income1 = pd.DataFrame({ 'Model' : models ,'Colors':color,'Year':years,'km':km,'Fiyat':prices })

income_sheets = {'Veriler': income1}

writer = pd.ExcelWriter('./Sayfa-10.xlsx', engine='xlsxwriter')

for sheet_name in income_sheets.keys():
    income_sheets[sheet_name].to_excel(writer, sheet_name=sheet_name, index=False)

writer.save()
#en son da dosyayı kaydediyoruz.

#Ben devamlı yazdıramadığım için en üstteki sayfa urlsini değiştirerek her seferinde yeni excel dosyasına yazdırdım. En sonunda excel dosyalarını birleştirdim.
#Bu şekilde 10 sayfayı aldım ve her sayfada 50 veri olduğu için toplam 500 veri etti.
