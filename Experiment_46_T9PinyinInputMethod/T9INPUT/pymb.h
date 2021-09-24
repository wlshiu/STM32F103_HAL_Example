#ifndef __PY_MB_h__
#define __PY_MB_h__
#include "pyinput.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//拼音输入法 代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/7/20
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved
//*******************************************************************************
//修改信息
//无
//////////////////////////////////////////////////////////////////////////////////

//汉字排列表
const u8 PY_mb_space [] = {""};
const u8 PY_mb_a     [] = {"啊阿腌吖锕厑嗄錒呵腌"};
const u8 PY_mb_ai    [] = {"爱埃挨哎唉哀皑癌蔼矮艾碍隘捱嗳嗌嫒瑷暧砹锿霭"};
const u8 PY_mb_an    [] = {"安俺按暗岸案鞍氨谙胺埯揞犴庵桉铵鹌黯"};
const u8 PY_mb_ang   [] = {"昂盎肮骯"};
const u8 PY_mb_ao    [] = {"凹敖熬翱袄傲奥懊澳坳拗嗷螯鏊鳌鏖岙廒遨媪骜獒聱"};
const u8 PY_mb_ba    [] = {"八巴爸拔芭捌扒叭吧笆疤跋靶把耙坝霸罢茇菝岜灞钯粑鲅魃"};
const u8 PY_mb_bai   [] = {"白柏百摆佰败拜稗伯捭掰"};
const u8 PY_mb_ban   [] = {"半办斑班搬扳般颁板版扮拌伴瓣绊阪坂贲钣瘢癍舨"};
const u8 PY_mb_bang  [] = {"邦帮梆榜膀绑棒磅蚌镑傍谤蒡浜"};
const u8 PY_mb_bao   [] = {"包宝保抱报暴苞胞褒剥薄雹堡饱豹鲍爆刨炮勹葆孢煲鸨褓趵龅"};
const u8 PY_mb_bei   [] = {"背贝北倍杯碑悲卑辈钡狈备惫焙被臂孛陂邶埤萆蓓呗悖碚鹎褙鐾鞴"};;
const u8 PY_mb_ben   [] = {"本笨奔苯畚坌贲锛"};
const u8 PY_mb_beng  [] = {"蚌崩绷甭泵蹦迸堋嘣甏"};
const u8 PY_mb_bi    [] = {"逼鼻比鄙笔彼碧蓖蔽毕毙毖币庇痹闭匕敝弊必辟壁臂避陛秘泌俾埤芘荜荸萆薜吡哔狴庳愎滗濞弼妣婢嬖璧贲畀铋秕裨筚箅篦舭襞跸髀"};
const u8 PY_mb_bian  [] = {"边编贬便变卞鞭扁辨辩辫遍匾弁苄忭汴缏煸砭碥窆褊蝙笾鳊"};
const u8 PY_mb_biao  [] = {"表标彪膘婊骠杓飑飙飚镖镳瘭裱鳔髟"};
const u8 PY_mb_bie   [] = {"别鳖憋瘪蹩"};
const u8 PY_mb_bin   [] = {"彬斌濒滨宾摈傧豳缤玢槟殡膑镔髌鬓"};
const u8 PY_mb_bing  [] = {"兵冰柄丙秉饼炳病并屏禀冫邴摒槟"};
const u8 PY_mb_bo    [] = {"柏百剥薄博玻菠卜播拨钵波勃搏铂箔伯帛舶脖膊渤泊驳孛亳蕃啵饽檗擘礴钹鹁簸趵跛踣"};
const u8 PY_mb_bu    [] = {"不布步堡捕卜哺补埠簿部怖埔卟逋瓿晡钚钸醭"};
const u8 PY_mb_ca    [] = {"擦嚓礤"};
const u8 PY_mb_cai   [] = {"才财睬猜裁材踩采彩菜蔡"};
const u8 PY_mb_can   [] = {"餐参蚕残惭惨灿孱骖璨粲黪"};
const u8 PY_mb_cang  [] = {"苍舱仓沧藏伧"};
const u8 PY_mb_cao   [] = {"草操糙槽曹艹嘈漕螬艚"};
const u8 PY_mb_ce    [] = {"侧册测厕策恻"};
const u8 PY_mb_cen   [] = {"参岑涔"};
const u8 PY_mb_ceng  [] = {"层蹭曾噌"};
const u8 PY_mb_cha   [] = {"插叉茬茶查碴搽察岔差诧刹喳衩嚓猹馇汊姹杈楂槎檫锸镲"};
const u8 PY_mb_chai  [] = {"差拆柴豺侪钗瘥虿龇"};
const u8 PY_mb_chan  [] = {"产阐颤搀掺蝉馋谗缠铲孱单冁谄蒇廛忏潺澶羼婵觇禅镡蟾躔"};
const u8 PY_mb_chang [] = {"长厂昌猖场尝常偿肠敞畅唱倡伥鬯苌菖徜怅惝阊娼嫦昶氅鲳"};
const u8 PY_mb_chao  [] = {"超抄钞朝嘲潮巢吵炒绰剿怊晁耖"};
const u8 PY_mb_che   [] = {"车扯撤掣彻澈坼屮砗"};
const u8 PY_mb_chen  [] = {"郴臣辰尘晨忱沉陈趁衬称谌谶抻嗔宸琛榇碜龀"};
const u8 PY_mb_cheng [] = {"撑称城橙成呈乘程惩澄诚承逞骋秤盛丞埕噌徵枨柽塍瞠铖铛裎蛏酲"};
const u8 PY_mb_chi   [] = {"吃痴持匙池迟弛驰耻齿侈尺赤翅斥炽笞叱哧傺坻墀茌啻嗤彳饬媸敕眵鸱瘛褫蚩螭篪豉踟魑"};
const u8 PY_mb_chong [] = {"充冲虫崇宠种重茺忡憧铳舂艟雠"};
const u8 PY_mb_chou  [] = {"抽酬丑畴踌稠愁筹仇绸瞅臭俦帱惆瘳雠"};
const u8 PY_mb_chu   [] = {"出初橱厨躇锄雏滁除楚础储矗搐触处畜亍刍怵憷绌杵楮樗褚蜍蹰黜"};
const u8 PY_mb_chuai [] = {"揣搋嘬膪踹"};
const u8 PY_mb_chuan [] = {"川穿椽传船喘串舛遄巛氚钏舡"};
const u8 PY_mb_chuang[] = {"疮窗幢床闯创怆疒"};
const u8 PY_mb_chui  [] = {"吹炊捶锤垂陲棰槌"};
const u8 PY_mb_chun  [] = {"春椿醇唇淳纯蠢莼鹑蝽"};
const u8 PY_mb_chuo  [] = {"戳绰啜辶辍踔龊"};
const u8 PY_mb_ci    [] = {"此刺赐次伺差疵茨磁雌辞慈瓷词兹茈呲祠鹚粢糍"};
const u8 PY_mb_cong  [] = {"从丛聪葱囱匆苁淙骢琮璁枞"};
const u8 PY_mb_cou   [] = {"凑楱辏腠"};
const u8 PY_mb_cu    [] = {"粗醋簇促蔟徂猝殂酢蹙蹴"};
const u8 PY_mb_cuan  [] = {"蹿篡窜攒汆撺爨镩"};
const u8 PY_mb_cui   [] = {"摧崔催脆瘁粹淬翠萃啐悴璀榱毳隹"};
const u8 PY_mb_cun   [] = {"村存寸忖皴"};
const u8 PY_mb_cuo   [] = {"磋撮搓措挫错厝嵯脞锉矬痤瘥鹾蹉躜"};
const u8 PY_mb_da    [] = {"大搭达答瘩打耷哒嗒怛妲沓疸褡笪靼鞑"};
const u8 PY_mb_dai   [] = {"大呆歹傣戴带殆代贷袋待逮怠黛埭甙呔岱迨骀绐玳"};
const u8 PY_mb_dan   [] = {"耽担丹单郸掸胆旦氮但惮淡诞弹蛋赡石儋萏啖澹殚赕眈疸瘅聃箪"};
const u8 PY_mb_dang  [] = {"当挡党荡档谠凼菪宕砀铛裆"};
const u8 PY_mb_dao   [] = {"刀捣蹈倒岛祷导到稻悼道盗刂叨帱忉氘焘纛"};
const u8 PY_mb_de    [] = {"德得的地锝"};
const u8 PY_mb_dei   [] = {"得"};
const u8 PY_mb_deng  [] = {"澄蹬灯登等瞪凳邓噔嶝戥磴镫簦"};
const u8 PY_mb_di    [] = {"的抵底地蒂第帝弟递堤低滴迪敌笛狄涤翟嫡缔提氐籴诋谛邸坻荻嘀娣柢棣觌砥碲睇镝羝骶"};
const u8 PY_mb_dia   [] = {"嗲"};
const u8 PY_mb_dian  [] = {"电店惦点典靛奠淀殿颠掂滇碘垫佃甸阽坫巅玷钿癜癫簟踮"};
const u8 PY_mb_diao  [] = {"吊刁掉钓调碉叼雕凋铞铫貂鲷"};
const u8 PY_mb_die   [] = {"跌爹碟蝶迭谍叠垤堞揲喋牒瓞耋蹀鲽"};
const u8 PY_mb_ding  [] = {"丁盯叮钉顶鼎锭定订仃啶玎腚碇町铤疔耵酊"};
const u8 PY_mb_diu   [] = {"丢铥"};
const u8 PY_mb_dong  [] = {"东冬董懂动栋侗恫冻洞咚岽峒氡胨胴硐鸫"};
const u8 PY_mb_dou   [] = {"豆逗痘都兜抖斗陡蔸窦蚪篼"};
const u8 PY_mb_du    [] = {"肚度渡都督毒犊独读堵睹赌杜镀妒芏嘟渎椟牍蠹笃髑黩"};
const u8 PY_mb_duan  [] = {"端短锻段断缎椴煅簖"};
const u8 PY_mb_dui   [] = {"堆兑队对怼憝碓"};
const u8 PY_mb_dun   [] = {"盾墩吨蹲敦顿囤钝遁沌炖砘礅盹镦趸"};
const u8 PY_mb_duo   [] = {"多朵度掇哆夺垛躲跺舵剁惰堕驮咄哚沲缍铎裰踱"};
const u8 PY_mb_e     [] = {"阿蛾峨鹅俄额讹娥恶厄扼遏鄂饿哦噩谔垩苊莪萼呃愕屙婀轭腭锇锷鹗颚鳄"};
const u8 PY_mb_ei    [] = {"诶"};
const u8 PY_mb_en    [] = {"恩蒽摁"};
const u8 PY_mb_er    [] = {"二而儿耳尔饵洱贰迩珥铒鸸鲕"};
const u8 PY_mb_fa    [] = {"发罚筏伐乏阀法珐垡砝"};
const u8 PY_mb_fan   [] = {"凡烦反返范贩犯饭泛藩帆番翻樊矾钒繁蕃蘩幡梵燔畈蹯"};
const u8 PY_mb_fang  [] = {"坊芳方肪房防妨仿访纺放匚邡枋钫舫鲂"};
const u8 PY_mb_fei   [] = {"菲非啡飞肥匪诽吠肺废沸费芾狒斐悱妃绯淝榧贲腓扉砩镄痱蜚篚翡霏鲱"};
const u8 PY_mb_fen   [] = {"分芬奋份忿愤粪酚吩氛纷坟焚汾粉偾瀵玢棼贲鲼鼢"};
const u8 PY_mb_feng  [] = {"丰封枫蜂峰锋风凤疯烽逢冯缝讽奉俸酆葑唪沣砜"};
const u8 PY_mb_fo    [] = {"佛"};
const u8 PY_mb_fou   [] = {"否缶"};
const u8 PY_mb_fu    [] = {"复佛傅付阜父夫敷肤孵妇扶拂辐幅氟符伏俘服浮涪福袱弗甫抚辅俯釜斧脯腑府腐赴副覆赋腹负富讣附缚咐匐凫阝郛芙芾苻茯莩菔拊呋幞怫滏艴孚驸绂绋桴赙祓砩黻黼罘稃馥蚨蜉蝠蝮麸趺跗鲋鳆"};
const u8 PY_mb_ga    [] = {"噶嘎夹咖伽尬尕尜旮钆"};
const u8 PY_mb_gai   [] = {"该改概钙盖溉芥丐陔垓戤赅胲"};
const u8 PY_mb_gan   [] = {"干甘杆柑竿肝赶感秆敢赣坩苷尴擀泔淦澉绀橄旰矸疳酐"};
const u8 PY_mb_gang  [] = {"冈刚钢缸肛纲岗港杠扛戆罡筻"};
const u8 PY_mb_gao   [] = {"告皋高膏篙羔糕搞镐稿睾诰郜藁缟槔槁杲锆"};
const u8 PY_mb_ge    [] = {"个各盖哥骼膈歌搁戈鸽胳疙割革葛格蛤阁隔铬合咯鬲仡哿圪塥嗝纥搿铪镉袼虼舸"};
const u8 PY_mb_gei   [] = {"给"};
const u8 PY_mb_gen   [] = {"根跟亘茛哏艮"};
const u8 PY_mb_geng  [] = {"耕更庚羹埂耿梗颈哽赓绠鲠"};
const u8 PY_mb_gong  [] = {"工共攻功恭公宫弓龚供躬巩汞拱贡蚣廾珙肱觥"};
const u8 PY_mb_gou   [] = {"钩勾沟苟够垢构购佝诟狗篝岣遘媾缑枸觏彀笱鞲"};
const u8 PY_mb_gu    [] = {"姑估沽孤菇咕辜箍鼓古蛊骨谷股故顾固雇贾嘏诂菰崮汩梏轱牯牿臌毂瞽罟钴锢鸪鹄痼蛄酤觚鲴鹘"};
const u8 PY_mb_gua   [] = {"刮瓜剐寡挂褂卦诖呱栝胍鸹"};
const u8 PY_mb_guai  [] = {"乖拐怪掴"};
const u8 PY_mb_guan  [] = {"关官冠观管馆罐惯灌贯纶倌莞棺掼涫盥鹳鳏"};
const u8 PY_mb_guang [] = {"光广逛咣犷桄胱"};
const u8 PY_mb_gui   [] = {"瑰规圭硅归龟闺轨鬼诡桂柜跪贵刽癸炔匦刿庋宄妫桧炅晷皈簋鲑鳜"};
const u8 PY_mb_gun   [] = {"辊滚棍衮绲磙鲧"};
const u8 PY_mb_guo   [] = {"锅郭国果裹过涡馘埚掴呙帼崞猓椁虢锞聒蜾蝈"};
const u8 PY_mb_ha    [] = {"哈蛤铪"};
const u8 PY_mb_hai   [] = {"还咳孩海害氦亥骇骸嗨胲醢"};
const u8 PY_mb_han   [] = {"汗汉喊寒含涵函罕酣旱憾悍焊憨邯韩翰撼鼾捍邗菡撖瀚晗焓顸颔蚶"};
const u8 PY_mb_hang  [] = {"行夯杭航吭巷沆绗颃"};
const u8 PY_mb_hao   [] = {"郝好耗号昊皓毫浩灏镐壕嚎豪貉蒿薅嗥嚆濠颢蚝"};
const u8 PY_mb_he    [] = {"呵喝荷菏核禾和何合河盒貉阂涸赫贺褐鹤吓诃劾壑嗬阖纥曷盍颌蚵翮"};
const u8 PY_mb_hei   [] = {"黑嘿"};
const u8 PY_mb_hen   [] = {"痕很狠恨"};
const u8 PY_mb_heng  [] = {"哼亨横衡恒蘅珩桁"};
const u8 PY_mb_hong  [] = {"红轰哄烘虹鸿洪宏弘黉訇讧荭蕻薨闳泓"};
const u8 PY_mb_hou   [] = {"后喉侯猴吼厚候堠後逅瘊篌糇鲎骺"};
const u8 PY_mb_hu    [] = {"护互沪户核呼乎忽瑚壶葫胡蝴虎狐糊湖弧唬冱唿囫岵猢怙惚浒滹琥槲轷觳烀煳戽扈祜瓠鹄鹕鹱虍笏醐斛鹘"};
const u8 PY_mb_hua   [] = {"花华猾滑哗画划化话骅桦砉铧"};
const u8 PY_mb_huai  [] = {"坏槐徊怀淮踝"};
const u8 PY_mb_huan  [] = {"欢环桓还缓换患唤痪焕涣宦幻鬟浣豢郇奂垸萑擐圜獾洹漶寰逭缳锾鲩"};
const u8 PY_mb_huang [] = {"晃荒慌黄磺蝗簧皇凰惶煌幌恍谎隍徨湟潢遑璜肓癀蟥篁鳇"};
const u8 PY_mb_hui   [] = {"会回毁悔灰挥辉徽恢蛔慧卉惠晦贿秽烩汇讳诲绘彗溃诙茴荟蕙咴哕喙隳洄浍缋桧晖恚虺蟪麾"};
const u8 PY_mb_hun   [] = {"荤昏婚魂浑混诨馄阍溷珲"};
const u8 PY_mb_huo   [] = {"和豁活伙火获或惑霍货祸劐藿攉嚯夥钬锪镬耠蠖"};
const u8 PY_mb_ji    [] = {"计记给技击基几脊己圾籍集及急疾汲即嫉级挤蓟既忌际冀季伎祭剂机畸稽积肌饥迹激讥鸡姬绩缉吉极棘箕辑悸济寄寂妓继纪藉奇系丌亟乩剞佶偈墼芨芰荠萁蒺蕺掎叽咭哜唧岌嵴洎彐屐骥畿玑楫殛戟戢赍觊犄齑矶羁嵇稷瘠虮笈笄暨跻跽霁鲚鲫髻麂"};
const u8 PY_mb_jia   [] = {"家加嘉夹佳荚颊贾甲钾假稼价架驾嫁枷茄嘏伽郏葭岬浃迦珈戛胛恝铗铪镓痂瘕袷蛱笳袈跏"};
const u8 PY_mb_jian  [] = {"建见件简健减歼荐监捡俭剪坚尖间煎兼肩艰奸缄茧检柬碱硷拣笺槛鉴践贱键箭舰剑饯渐溅涧僭谏谫谮菅蒹搛囝湔蹇謇缣枧楗戋戬牮犍毽腱睑锏鹣裥笕翦趼踺鲣鞯"};
const u8 PY_mb_jiang [] = {"讲虹僵姜将浆江疆蒋桨奖匠酱降强茳洚绛缰犟礓耩糨豇"};
const u8 PY_mb_jiao  [] = {"叫较觉角校蕉椒礁焦胶交郊浇骄娇嚼搅铰矫侥脚狡饺缴绞剿教酵轿窖佼僬艽茭挢噍峤徼姣敫皎鹪蛟醮跤鲛"};
const u8 PY_mb_jie   [] = {"洁结解姐戒揭杰接皆界借介捷睫秸街阶截劫节桔竭藉芥疥诫届偈讦诘卩拮喈嗟婕孑桀碣锴疖颉蚧羯鲒骱"};
const u8 PY_mb_jin   [] = {"巾尽筋斤金今津紧锦仅谨进靳晋禁近烬浸劲襟卺荩堇噤馑廑妗缙瑾槿赆觐钅衿矜"};
const u8 PY_mb_jing  [] = {"京惊精经井睛晶景净颈静境敬警镜径竟竞劲荆兢茎鲸粳痉靖刭儆阱陉菁獍憬泾迳弪婧肼胫腈旌靓"};
const u8 PY_mb_jiong [] = {"炯窘冂迥扃"};
const u8 PY_mb_jiu   [] = {"九就救揪究纠玖韭久灸酒旧臼舅咎疚厩僦啾阄柩桕鸠鹫赳鬏"};
const u8 PY_mb_ju    [] = {"巨具距俱句惧车柜剧居驹菊局咀矩举沮聚拒据踞锯炬鞠拘狙疽倨讵苣苴莒掬遽屦琚枸椐榘榉橘犋飓钜锔窭裾趄醵踽龃雎瞿鞫"};
const u8 PY_mb_juan  [] = {"眷卷捐鹃娟倦绢圈鄄狷涓桊蠲锩镌隽"};
const u8 PY_mb_jue   [] = {"决诀绝觉角掘倔嚼脚撅攫抉爵厥劂谲矍堀蕨噘崛獗孓珏桷橛爝镢蹶觖"};
const u8 PY_mb_jun   [] = {"军君均菌钧峻俊竣浚郡骏龟捃皲筠麇"};
const u8 PY_mb_ka    [] = {"卡喀咖咯佧咔胩"};
const u8 PY_mb_kai   [] = {"开揩楷凯慨剀垲蒈忾恺铠锎锴"};
const u8 PY_mb_kan   [] = {"看刊堪勘坎砍侃龛瞰凵莰阚槛戡"};
const u8 PY_mb_kang  [] = {"康慷糠扛抗亢炕伉闶钪"};
const u8 PY_mb_kao   [] = {"考靠拷烤栲犒铐尻"};
const u8 PY_mb_ke    [] = {"可渴克科刻客课嗑坷苛柯棵磕颗壳咳恪蝌岢溘稞骒缂珂轲氪瞌钶铪呵锞疴窠颏蚵髁"};
const u8 PY_mb_ken   [] = {"肯啃垦恳裉"};
const u8 PY_mb_keng  [] = {"坑吭铿胫铒"};
const u8 PY_mb_kong  [] = {"空恐孔控倥崆箜"};
const u8 PY_mb_kou   [] = {"抠口扣寇芤蔻叩眍筘"};
const u8 PY_mb_ku    [] = {"枯哭窟苦酷库裤绔骷刳堀喾"};
const u8 PY_mb_kua   [] = {"夸垮挎跨胯侉锞"};
const u8 PY_mb_kuai  [] = {"会块筷侩快蒯郐哙狯脍"};
const u8 PY_mb_kuan  [] = {"宽款髋"};
const u8 PY_mb_kuang [] = {"况匡筐狂框矿眶旷诓诳邝圹夼哐纩贶"};
const u8 PY_mb_kui   [] = {"亏盔岿窥葵奎魁傀馈愧溃馗匮逵睽跬夔隗蒉揆喹喟悝愦暌聩蝰篑"};
const u8 PY_mb_kun   [] = {"坤昆捆困悃琨锟醌鲲阃髡"};
const u8 PY_mb_kuo   [] = {"括扩廓阔蛞"};
const u8 PY_mb_la    [] = {"垃拉喇蜡腊辣啦落剌邋旯砬瘌"};
const u8 PY_mb_lai   [] = {"莱来赖崃徕涞濑赉睐癞籁铼"};
const u8 PY_mb_lan   [] = {"蓝婪栏拦篮阑兰澜谰揽览懒缆烂滥岚漤榄斓镧褴罱"};
const u8 PY_mb_lang  [] = {"郎朗浪琅榔狼廊啷阆螂锒蒗稂莨"};
const u8 PY_mb_lao   [] = {"捞劳牢老佬姥酪烙涝落络唠崂醪栳铑铹痨耢"};
const u8 PY_mb_le    [] = {"勒乐了仂叻泐鳓"};
const u8 PY_mb_lei   [] = {"累勒雷镭蕾磊儡垒擂肋类泪羸诔嘞嫘缧檑耒酹"};
const u8 PY_mb_leng  [] = {"棱楞冷塄愣"};
const u8 PY_mb_li    [] = {"利力历厉立粒礼沥吏理李里厘励丽梨犁隶黎篱离漓鲤栗砾莉荔狸傈例俐痢璃哩鬲俪俚郦坜苈莅蓠藜呖唳喱猁溧澧逦娌嫠骊缡枥栎轹戾砺砬詈罹锂鹂疠疬蛎蜊蠡笠篥粝醴跞雳鲡鳢黧"};
const u8 PY_mb_lia   [] = {"俩"};
const u8 PY_mb_lian  [] = {"联莲连廉怜涟帘敛脸链恋炼练潋镰濂琏楝奁殓蔹臁裢裣蠊鲢"};
const u8 PY_mb_liang [] = {"两亮俩粮凉梁粱良辆量晾谅墚莨椋踉魉"};
const u8 PY_mb_liao  [] = {"了撩料聊僚疗燎寥辽潦撂镣廖蓼尥嘹獠寮缭钌鹩"};
const u8 PY_mb_lie   [] = {"列裂烈劣洌猎冽埒捩咧趔躐鬣"};
const u8 PY_mb_lin   [] = {"临邻赁拎琳林磷霖鳞淋凛吝蔺啉嶙廪懔遴檩辚膦瞵粼躏麟"};
const u8 PY_mb_ling  [] = {"令灵另棱玲菱零龄铃伶羚凌陵岭聆领酃苓呤囹泠绫柃棂瓴蛉翎鲮"};
const u8 PY_mb_liu   [] = {"刘六溜琉榴硫馏留瘤流柳碌陆浏遛骝绺旒熘锍镏鹨鎏"};
const u8 PY_mb_lo    [] = {"咯"};
const u8 PY_mb_long  [] = {"龙弄聋咙笼窿隆垄拢陇垅茏泷珑栊胧砻癃"};
const u8 PY_mb_lou   [] = {"楼娄搂篓漏陋露偻蒌喽嵝镂瘘耧蝼髅"};
const u8 PY_mb_lu    [] = {"六芦卢颅庐炉掳卤虏鲁麓碌露路赂鹿潞禄录陆戮绿垆撸噜泸渌漉逯璐栌橹轳辂辘贲氇胪镥鸬鹭簏舻鲈"};
const u8 PY_mb_lv    [] = {"滤率绿吕铝侣旅履屡缕虑氯律驴褛偻捋闾榈膂稆"};
const u8 PY_mb_luan  [] = {"乱孪峦挛滦卵"};
const u8 PY_mb_lue   [] = {"掠略锊"};
const u8 PY_mb_lun   [] = {"仑抡轮伦沦纶论囵"};
const u8 PY_mb_luo   [] = {"落罗铬咯烙萝螺逻锣箩骡裸洛骆络倮蠃荦捋摞猡泺漯珞椤脶硌镙瘰雒"};
const u8 PY_mb_m     [] = {"呒"};
const u8 PY_mb_ma    [] = {"妈麻玛码蚂马骂嘛吗摩抹唛犸嬷杩蟆"};
const u8 PY_mb_mai   [] = {"埋瞒馒蛮满蔓曼慢漫谩墁幔缦熳镘颟螨鳗鞔"};
const u8 PY_mb_man   [] = {"蛮馒瞒满曼谩慢漫蔓"};
const u8 PY_mb_mang  [] = {"芒茫盲氓忙莽邙漭硭蟒"};
const u8 PY_mb_mao   [] = {"猫茅锚毛矛髦卯茂冒帽貌贸袤铆茆峁泖瑁昴牦耄旄懋瞀蝥蟊"};
const u8 PY_mb_me    [] = {"么"};
const u8 PY_mb_mei   [] = {"每妹美玫枚昧寐袂魅梅酶霉煤没眉媒镁媚莓嵋猸浼湄楣镅鹛"};
const u8 PY_mb_men   [] = {"门闷们扪焖懑钔"};
const u8 PY_mb_meng  [] = {"萌梦蒙檬盟锰猛孟勐甍瞢懵朦礞虻蜢蠓艋艨"};
const u8 PY_mb_mi    [] = {"眯醚靡糜迷谜弥米秘觅泌蜜密麋谧幂芈冖蘼咪嘧猕汨宓弭纟脒祢敉糸縻"};
const u8 PY_mb_mian  [] = {"面棉眠绵冕免勉娩缅沔渑湎宀腼眄"};
const u8 PY_mb_miao  [] = {"苗描瞄藐秒渺庙妙喵邈缈缪杪淼眇鹋"};
const u8 PY_mb_mie   [] = {"蔑灭乜咩篾蠛"};
const u8 PY_mb_min   [] = {"民抿皿敏悯闽苠岷闵泯缗玟珉愍黾鳘"};
const u8 PY_mb_ming  [] = {"明螟鸣铭名命冥茗溟暝瞑酩"};
const u8 PY_mb_miu   [] = {"谬缪"};
const u8 PY_mb_mo    [] = {"脉没摸摹蘑模膜磨摩魔抹末莫墨默沫漠寞陌麽万谟茉蓦馍嫫殁镆秣瘼耱貊貘"};
const u8 PY_mb_mou   [] = {"谋牟某侔哞缪眸蛑鍪"};
const u8 PY_mb_mu    [] = {"木目睦模牟拇牡亩姆母墓暮幕募慕牧穆苜沐仫坶毪钼"};
const u8 PY_mb_na    [] = {"拿哪呐钠那娜纳捺肭镎衲"};
const u8 PY_mb_nai   [] = {"氖乃奶耐奈鼐佴艿萘柰"};
const u8 PY_mb_nan   [] = {"南男难喃囡楠腩蝻赧"};
const u8 PY_mb_nang  [] = {"囊囔馕攮曩"};
const u8 PY_mb_nao   [] = {"挠脑恼闹淖孬垴呶猱瑙硇铙蛲"};
const u8 PY_mb_ne    [] = {"哪呢讷"};
const u8 PY_mb_nei   [] = {"内馁"};
const u8 PY_mb_nen   [] = {"嫩恁"};
const u8 PY_mb_neng  [] = {"能"};
const u8 PY_mb_ng    [] = {"嗯"};
const u8 PY_mb_ni    [] = {"你呢拟尼妮霓倪泥匿腻逆溺伲坭猊怩昵旎祢慝睨铌鲵"};
const u8 PY_mb_nian  [] = {"蔫拈年碾撵捻念廿埝辇黏鲇鲶"};
const u8 PY_mb_niang [] = {"娘酿"};
const u8 PY_mb_niao  [] = {"鸟尿脲袅茑嬲"};
const u8 PY_mb_nie   [] = {"捏聂孽啮镊镍涅蹑蘖嗫乜陧颞臬"};
const u8 PY_mb_nin   [] = {"您"};
const u8 PY_mb_ning  [] = {"柠狞凝宁拧泞佞咛甯聍"};
const u8 PY_mb_niu   [] = {"牛扭钮纽拗妞狃忸"};
const u8 PY_mb_nong  [] = {"脓浓农弄侬哝"};
const u8 PY_mb_nou   [] = {"耨"};
const u8 PY_mb_nu    [] = {"奴努怒弩胬孥驽"};
const u8 PY_mb_nuan  [] = {"暖"};
const u8 PY_mb_nue   [] = {"疟虐"};
const u8 PY_mb_nuo   [] = {"娜挪懦糯诺傩搦喏锘"};
const u8 PY_mb_nv    [] = {"女恧钕衄"};
const u8 PY_mb_o     [] = {"哦喔噢"};
const u8 PY_mb_ou    [] = {"欧鸥殴藕呕偶沤区讴怄瓯耦"};
const u8 PY_mb_pa    [] = {"扒耙啪趴爬帕怕琶葩杷筢"};
const u8 PY_mb_pai   [] = {"拍排牌徘湃派迫俳蒎哌"};
const u8 PY_mb_pan   [] = {"番攀潘盘磐盼畔判叛蟠蹒胖拚丬爿泮贲袢襻"};
const u8 PY_mb_pang  [] = {"膀磅镑乓庞旁耪胖彷滂螃逄"};
const u8 PY_mb_pao   [] = {"抛咆刨炮袍跑泡狍庖疱脬匏"};
const u8 PY_mb_pei   [] = {"呸胚培裴赔陪配佩沛辔霈帔旆锫醅"};
const u8 PY_mb_pen   [] = {"喷盆湓"};
const u8 PY_mb_peng  [] = {"捧碰砰抨烹澎彭蓬棚硼篷膨朋鹏怦堋嘭蟛"};
const u8 PY_mb_pi    [] = {"辟否坯砒霹批披劈琵毗啤脾疲皮匹痞僻丕屁譬癖貔仳陂陴邳郫圮埤鼙芘擗噼庀淠媲纰枇甓睥罴铍裨疋蚍蜱"};
const u8 PY_mb_pian  [] = {"扁便篇偏片骗谝骈缏犏胼翩蹁"};
const u8 PY_mb_piao  [] = {"飘漂瓢票朴剽嫖缥瞟嘌骠殍螵"};
const u8 PY_mb_pie   [] = {"撇瞥丿苤氕"};
const u8 PY_mb_pin   [] = {"拼频贫品聘姘嫔榀牝颦"};
const u8 PY_mb_ping  [] = {"冯乒坪苹萍平凭瓶评屏俜娉枰鲆"};
const u8 PY_mb_po    [] = {"泊繁坡泼颇婆破魄迫粕朴叵陂鄱珀攴攵钋钷皤笸"};
const u8 PY_mb_pou   [] = {"剖裒掊"};
const u8 PY_mb_pu    [] = {"普堡暴脯扑铺仆莆葡菩蒲埔朴圃浦谱曝瀑匍噗溥蹼濮璞氆镤镨"};
const u8 PY_mb_qi    [] = {"七起妻乞企启稽缉期欺栖戚凄漆柒沏其棋奇歧畦崎脐齐旗祈岐祁骑岂琪琦杞契砌器气迄弃汽泣讫亟祺憩蹊鳍麒亓俟圻芑芪荠萋葺淇骐绮耆蕲桤槭欹嘁屺汔碛颀蛴蜞綦綮"};
const u8 PY_mb_qia   [] = {"卡掐恰洽葜袷髂"};
const u8 PY_mb_qian  [] = {"牵扦钎铅千迁签仟谦乾黔钱钳前潜遣浅谴堑嵌欠歉纤倩佥阡芊芡茜荨掮岍悭慊骞搴褰缱椠犍肷愆钤虔箝羟"};
const u8 PY_mb_qiang [] = {"枪呛腔羌墙蔷强抢跄戕戗炝锵镪丬襁嫱樯蜣羟"};
const u8 PY_mb_qiao  [] = {"壳橇锹敲悄桥瞧乔侨巧鞘撬翘峭俏窍雀诮谯荞峤憔樵跷鞒缲劁愀硗铫"};
const u8 PY_mb_qie   [] = {"切茄且怯窃伽惬慊妾趄郄挈锲箧"};
const u8 PY_mb_qin   [] = {"钦侵亲秦琴勤芹擒禽寝沁芩揿衾吣嗪噙廑檎锓矜覃螓"};
const u8 PY_mb_qing  [] = {"亲青轻氢倾卿清擎晴氰情顷请庆磬苘圊檠锖蜻罄箐綮謦鲭黥"};
const u8 PY_mb_qiong [] = {"琼穷穹蛩邛茕筇跫銎"};
const u8 PY_mb_qiu   [] = {"仇龟秋丘邱球求囚酋泅俅逑裘糗遒巯犰湫楸赇虬蚯蝤鳅"};
const u8 PY_mb_qu    [] = {"趋区蛆曲躯屈驱渠取娶龋趣去蛐黢戌诎劬凵苣蕖蘧岖衢阒璩觑氍朐祛磲鸲癯蠼麴瞿"};
const u8 PY_mb_quan  [] = {"圈颧权醛泉全痊拳犬券劝诠荃蜷鬈犭悛绻辁畎铨筌"};
const u8 PY_mb_que   [] = {"缺炔瘸却鹊榷确雀阕阙悫"};
const u8 PY_mb_qui   [] = {"鼽"};
const u8 PY_mb_qun   [] = {"裙群逡麇"};
const u8 PY_mb_ran   [] = {"然燃冉染苒蚺髯"};
const u8 PY_mb_rang  [] = {"瓤壤攘嚷让禳穰"};
const u8 PY_mb_rao   [] = {"饶扰绕荛娆桡"};
const u8 PY_mb_re    [] = {"惹热喏"};
const u8 PY_mb_ren   [] = {"壬仁人忍韧任认刃妊纫稔亻仞荏葚饪轫衽"};
const u8 PY_mb_reng  [] = {"扔仍"};
const u8 PY_mb_ri    [] = {"日"};
const u8 PY_mb_rong  [] = {"戎茸蓉荣融熔溶容绒冗嵘狨榕肜蝾"};
const u8 PY_mb_rou   [] = {"揉柔肉糅蹂鞣"};
const u8 PY_mb_ru    [] = {"茹蠕儒孺如辱乳汝入濡褥溽蓐嚅薷洳缛铷襦颥"};
const u8 PY_mb_ruan  [] = {"软阮朊"};
const u8 PY_mb_rui   [] = {"蕊瑞锐芮睿枘蕤蚋"};
const u8 PY_mb_run   [] = {"闰润"};
const u8 PY_mb_ruo   [] = {"若弱偌箬"};
const u8 PY_mb_sa    [] = {"撒洒萨卅仨飒脎"};
const u8 PY_mb_sai   [] = {"腮鳃塞赛噻"};
const u8 PY_mb_san   [] = {"三叁伞散馓毵糁"};
const u8 PY_mb_sang  [] = {"桑嗓丧搡磉颡"};
const u8 PY_mb_sao   [] = {"搔骚扫嫂臊瘙埽缫鳋"};
const u8 PY_mb_se    [] = {"塞瑟色涩啬铯穑"};
const u8 PY_mb_sen   [] = {"森"};
const u8 PY_mb_seng  [] = {"僧"};
const u8 PY_mb_sha   [] = {"莎砂杀刹沙纱傻啥煞杉厦痧裟霎鲨唼歃铩"};
const u8 PY_mb_shai  [] = {"色筛晒"};
const u8 PY_mb_shan  [] = {"掺单珊苫杉山删煽衫闪陕擅赡膳善汕扇缮栅讪疝舢蟮跚鳝剡鄯埏芟彡潸姗嬗骟膻禅钐髟"};
const u8 PY_mb_shang [] = {"墒伤商赏晌上尚裳绱殇觞垧熵"};
const u8 PY_mb_shao  [] = {"鞘梢捎稍烧芍勺韶少哨邵绍劭苕艄潲杓蛸筲"};
const u8 PY_mb_she   [] = {"奢赊蛇舌舍赦摄射慑涉社设麝折厍佘揲猞滠歙畲铊"};
const u8 PY_mb_shei  [] = {"谁"};
const u8 PY_mb_shen  [] = {"什参砷申呻伸身深娠绅神沈审婶甚肾慎渗诜谂莘葚哂渖椹胂矧蜃"};
const u8 PY_mb_sheng [] = {"乘声生甥牲升绳省盛剩胜圣笙嵊渑晟眚"};
const u8 PY_mb_shi   [] = {"是事匙师十石失狮施湿诗尸虱拾时什食蚀实识史矢使屎驶始式示士世柿拭誓逝势嗜噬适仕侍释饰氏市恃室视试似弑舐殖峙谥埘莳蓍饣轼贳炻礻铈铊螫筮酾豕鲥鲺"};
const u8 PY_mb_shou  [] = {"收手首守寿授售受瘦兽扌狩绶艏"};
const u8 PY_mb_shu   [] = {"蔬枢梳殊抒输叔舒淑疏书赎孰熟薯暑曙署蜀黍鼠属术述树束戍竖墅庶数漱恕倏塾沭澍姝丨菽摅纾毹腧殳镯秫疋"};
const u8 PY_mb_shua  [] = {"刷耍唰"};
const u8 PY_mb_shuai [] = {"率摔衰甩帅蟀"};
const u8 PY_mb_shuan [] = {"栓拴闩涮"};
const u8 PY_mb_shuang[] = {"霜双爽泷孀"};
const u8 PY_mb_shui  [] = {"水睡税说氵"};
const u8 PY_mb_shun  [] = {"吮瞬顺舜"};
const u8 PY_mb_shuo  [] = {"数说硕朔烁蒴搠妁槊铄"};
const u8 PY_mb_si    [] = {"斯撕嘶思私司丝死肆寺嗣四伺似饲巳厮咝俟兕厶饣汜泗澌姒驷缌祀锶鸶耜蛳笥"};
const u8 PY_mb_song  [] = {"松耸怂颂送宋讼诵嵩忪悚淞竦崧菘凇"};
const u8 PY_mb_sou   [] = {"搜艘擞嗽叟嗖馊溲飕瞍锼螋嗾薮"};
const u8 PY_mb_su    [] = {"苏酥俗素速粟僳塑溯宿诉肃缩夙愫涑簌稣谡蔌嗉觫"};
const u8 PY_mb_suan  [] = {"酸蒜算狻"};
const u8 PY_mb_sui   [] = {"虽岁绥隋随髓祟遂碎隧穗"};
const u8 PY_mb_sun   [] = {"孙损笋"};
const u8 PY_mb_suo   [] = {"蓑梭唆缩琐索锁所唢嗦嗍娑莎桫挲睃羧"};
const u8 PY_mb_ta    [] = {"塌他它她塔獭挞沓蹋踏拓闼遢榻铊趿溻鳎漯"};
const u8 PY_mb_tai   [] = {"胎苔抬台泰酞太态汰跆邰薹骀肽炱钛鲐"};
const u8 PY_mb_tan   [] = {"弹坍摊贪瘫滩坛檀痰潭谭谈坦毯袒碳探叹炭覃郯澹昙赕忐钽锬镡"};
const u8 PY_mb_tang  [] = {"汤塘搪堂棠膛唐糖倘躺淌趟烫傥饧溏瑭樘铛螳铴镗耥螗羰醣帑"};
const u8 PY_mb_tao   [] = {"掏涛滔绦萄桃逃淘陶讨套叨啕饕洮韬焘鼗"};
const u8 PY_mb_te    [] = {"特忒忑铽"};
const u8 PY_mb_teng  [] = {"藤腾疼滕誊"};
const u8 PY_mb_ti    [] = {"梯剔踢锑提题蹄啼体替嚏惕涕剃屉倜悌缇荑逖绨鹈裼醍"};
const u8 PY_mb_tian  [] = {"天添填田甜恬舔腆殄掭忝阗畋钿锘"};
const u8 PY_mb_tiao  [] = {"调挑条迢眺跳佻髫苕祧铫窕蜩笤粜龆鲦"};
const u8 PY_mb_tie   [] = {"贴铁帖餮锇萜"};
const u8 PY_mb_ting  [] = {"厅听烃汀廷停亭庭挺艇莛葶婷铤蜓霆梃"};
const u8 PY_mb_tong  [] = {"桐瞳同铜彤童桶捅筒统痛佟僮茼恸潼酮仝垌嗵峒砼"};
const u8 PY_mb_tou   [] = {"偷投头透骰钭亠"};
const u8 PY_mb_tu    [] = {"凸秃突图徒途涂屠土吐兔堍荼菟钍酴"};
const u8 PY_mb_tuan  [] = {"湍团抟彖疃"};
const u8 PY_mb_tui   [] = {"推颓腿蜕褪退煺"};
const u8 PY_mb_tun   [] = {"囤褪吞屯臀饨豚氽暾"};
const u8 PY_mb_tuo   [] = {"说拖拓托脱鸵陀驮驼椭妥唾跎乇佗坨沱柝柁橐砣铊鼍箨酡庹"};
const u8 PY_mb_wa    [] = {"挖哇蛙洼娃瓦袜佤娲腽"};
const u8 PY_mb_wai   [] = {"歪外崴"};
const u8 PY_mb_wan   [] = {"蔓豌弯湾玩顽丸烷完碗挽晚皖惋宛婉万腕剜芄莞菀纨蜿绾琬脘畹鞔"};
const u8 PY_mb_wang  [] = {"汪王亡枉网往旺望忘妄罔惘魍尢辋"};
const u8 PY_mb_wei   [] = {"为位谓威巍微危韦维违桅围唯惟潍苇萎委伟伪尾纬未蔚味畏胃喂魏渭尉慰卫偎诿隗圩葳薇帏帷崴嵬猬逶娓痿炜玮闱猥隈沩洧涠韪軎煨艉鲔囗"};
const u8 PY_mb_wen   [] = {"问文闻纹瘟温蚊吻稳紊刎雯玟阌汶璺"};
const u8 PY_mb_weng  [] = {"嗡翁瓮蓊蕹"};
const u8 PY_mb_wo    [] = {"我握喔蜗涡窝斡卧沃挝倭莴幄龌渥肟硪"};
const u8 PY_mb_wu    [] = {"五物勿务午舞伍武侮恶悟误兀巫雾呜钨乌污诬屋无芜梧吾吴毋捂坞戊晤仵邬鹉圬芴唔庑怃忤鹜痦蜈浯寤迕妩婺骛阢杌牾於焐鋈鼯"};
const u8 PY_mb_xi    [] = {"希习夕戏细昔熙析西硒矽晰嘻吸锡牺稀蹊息悉膝惜熄溪汐犀袭席媳喜洗系隙羲皙屣嬉玺樨奚茜檄烯铣匚僖兮隰郗菥葸蓰唏徙饩阋浠淅曦觋欷歙熹禊禧穸裼蜥螅蟋舄舾粞翕醯鼷"};
const u8 PY_mb_xia   [] = {"瞎虾匣霞辖暇峡侠狭下厦夏吓呷狎遐瑕柙硖罅黠"};
const u8 PY_mb_xian  [] = {"现先仙嫌显险献县贤铣洗掀锨鲜纤咸衔舷闲涎弦腺馅羡宪陷限线冼苋莶藓岘猃暹娴氙燹祆鹇痃痫蚬筅籼酰跣跹霰"};
const u8 PY_mb_xiang [] = {"像向象降相厢镶香箱湘乡翔祥详想响享项巷橡襄飨芗葙饷庠骧缃蟓鲞"};
const u8 PY_mb_xiao  [] = {"小消肖萧硝霄削哮嚣销宵淆晓孝校啸笑效哓潇逍筱箫骁绡枭枵蛸魈"};
const u8 PY_mb_xie   [] = {"些歇蝎鞋协挟携邪斜胁谐写械卸蟹懈泄泻谢屑血解楔叶偕亵勰燮薤撷獬廨渫瀣邂绁缬榭榍颉躞鲑骱"};
const u8 PY_mb_xin   [] = {"薪芯锌欣辛新忻心信衅馨莘歆鑫昕囟忄镡"};
const u8 PY_mb_xing  [] = {"幸省星腥猩惺兴刑型形邢行醒杏性姓饧陉荇荥擤悻硎"};
const u8 PY_mb_xiong [] = {"兄凶胸匈汹雄熊芎"};
const u8 PY_mb_xiu   [] = {"臭宿休修羞朽嗅锈秀袖绣咻溴貅馐岫庥鸺髹"};
const u8 PY_mb_xu    [] = {"续绪墟戌需虚嘘须徐许蓄酗叙旭序畜恤絮婿诩煦勖圩蓿洫浒溆顼栩吁胥盱糈醑"};
const u8 PY_mb_xuan  [] = {"玄选轩喧宣渲悬旋暄绚炫眩癣儇谖萱泫漩璇楦煊揎碹铉镟券"};
const u8 PY_mb_xue   [] = {"削靴薛学穴雪血鳕谑噱泶踅"};
const u8 PY_mb_xun   [] = {"寻旬迅讯询训勋熏循驯巡殉汛逊郇埙荀薰峋徇醺鲟浚荨蕈獯巽恂洵浔曛窨"};
const u8 PY_mb_ya    [] = {"牙芽亚哑压雅押鸦鸭呀丫崖衙涯讶轧伢蚜垭揠岈迓娅琊桠氩砑睚痖疋"};
const u8 PY_mb_yan   [] = {"言演验厌严沿炎燕咽阉奄掩眼烟淹盐研岩延颜阎衍艳堰砚雁唁焉彦焰宴谚蜒闫妍嫣胭腌焱恹俨偃铅殷厣赝剡兖讠谳阽郾鄢芫菸崦魇阏湮滟琰檐晏罨筵酽餍鼹鼽"};
const u8 PY_mb_yang  [] = {"央仰羊洋阳养样杨扬恙殃鸯秧佯氧疡痒漾徉怏泱炀烊蛘鞅"};
const u8 PY_mb_yao   [] = {"要邀咬药腰妖摇尧肴窈遥窑谣姚舀耀钥夭爻幺吆瑶啮疟侥崤崾徭珧杳轺曜铫鹞繇鳐"};
const u8 PY_mb_ye    [] = {"也页业叶夜液椰噎耶爷野冶掖曳腋邪咽谒盅靥邺揶琊晔烨铘"};
const u8 PY_mb_yi    [] = {"一乙已以忆义议谊译异益壹医揖铱依伊衣颐夷遗移仪胰疑沂宜姨彝椅蚁倚矣艺抑易邑屹亿役臆逸肄疫亦裔意毅溢诣翼翌艾尾绎刈劓佚佾诒阝圯埸懿苡荑薏弈奕挹弋呓咦咿噫峄嶷猗饴怿怡悒漪迤驿缢殪轶贻欹旖熠眙钇铊镒镱痍瘗癔翊衤蜴舣羿翳酏黟"};
const u8 PY_mb_yin   [] = {"尹引印茵荫因殷音阴姻吟银淫寅饮隐龈胤蚓鄞廴垠堙茚吲喑狺夤洇湮氤铟瘾窨霪"};
const u8 PY_mb_ying  [] = {"映影英莹萤营荧樱婴鹰应缨蝇迎赢盈颖硬嬴莺萦鹦潆瀛滢瑛郢茔荥蓥撄嘤膺璎楹媵瘿颍罂"};
const u8 PY_mb_yo    [] = {"哟育唷"};
const u8 PY_mb_yong  [] = {"用拥佣勇涌臃痈庸雍踊蛹咏泳永恿俑壅墉喁慵邕镛甬鳙饔"};
const u8 PY_mb_you   [] = {"尤有又诱幼友右佑幽优悠忧由邮铀犹油游酉釉呦疣鱿黝鼬蚰攸卣侑莠莜莸尢囿宥柚猷牖铕蚴蝣蝤繇"};
const u8 PY_mb_yu    [] = {"余与于予宇玉雨育誉浴鱼迂淤盂虞愚舆俞逾愉渝渔隅娱屿禹语羽域芋郁吁遇喻峪御愈榆欲狱寓裕预豫驭竽毓谀於谕蔚尉禺伛俣萸菀蓣揄圄圉嵛狳饫馀庾阈鬻妪妤纡瑜昱觎腴欤煜熨燠肀聿钰鹆鹬瘐瘀窬窳蜮蝓臾舁雩龉"};
const u8 PY_mb_yuan  [] = {"原元园员圆源缘远愿怨院鸳渊冤垣袁援辕猿苑媛塬芫掾圜沅瑗橼爰眢鸢螈箢鼋"};
const u8 PY_mb_yue   [] = {"月悦阅乐说曰约越跃钥岳粤龠哕瀹栎樾刖钺"};
const u8 PY_mb_yun   [] = {"云员允运晕耘匀陨蕴酝熨韵孕氲殒芸郧郓狁恽愠纭韫昀筠"};
const u8 PY_mb_za    [] = {"匝砸杂扎咋咂拶"};
const u8 PY_mb_zai   [] = {"再在栽哉灾宰载崽甾"};
const u8 PY_mb_zan   [] = {"咱攒暂赞昝簪拶瓒糌趱錾"};
const u8 PY_mb_zang  [] = {"藏赃脏葬驵臧"};
const u8 PY_mb_zao   [] = {"枣遭早造皂灶糟凿澡躁噪燥藻蚤唣"};
const u8 PY_mb_ze    [] = {"责择则泽咋仄赜啧帻迮昃笮箦舴"};
const u8 PY_mb_zei   [] = {"贼"};
const u8 PY_mb_zen   [] = {"怎谮"};
const u8 PY_mb_zeng  [] = {"增憎曾赠缯甑罾锃"};
const u8 PY_mb_zha   [] = {"扎闸查喳渣札轧铡眨栅榨咋乍炸诈吒咤柞揸蚱哳喋楂砟痄龃齄"};
const u8 PY_mb_zhai  [] = {"宅窄债翟择摘斋寨砦瘵"};
const u8 PY_mb_zhan  [] = {"占战站展沾绽瞻毡詹粘盏斩辗崭蘸颤栈湛谵搌骣旃"};
const u8 PY_mb_zhang [] = {"张丈仗胀杖樟章彰漳掌涨帐账长瘴障幛嶂獐蟑仉鄣嫜璋"};
const u8 PY_mb_zhao  [] = {"找召爪着兆朝招昭诏沼赵照罩肇钊笊啁棹"};
const u8 PY_mb_zhe   [] = {"遮折哲蛰辙者锗蔗这浙着谪摺柘辄磔鹧褶蜇赭"};
const u8 PY_mb_zhen  [] = {"真贞针震振诊阵镇侦枕珍疹斟甄箴臻帧圳砧蓁浈溱缜桢椹榛轸赈胗朕祯畛稹鸩"};
const u8 PY_mb_zheng [] = {"正证蒸挣睁征狰争怔整拯政症郑诤峥徵钲铮筝鲭"};
const u8 PY_mb_zhi   [] = {"只职识执值直植殖治支纸志址指质置制止至侄芝之汁旨枝知肢脂织趾挚掷致帜峙智秩稚吱蜘炙痔滞窒枳芷卮陟郅埴摭帙徵夂忮彘咫骘栉栀桎轵轾贽胝膣祉祗黹雉鸷痣蛭絷酯跖踬踯豸觯"};
const u8 PY_mb_zhong [] = {"中众忠钟衷终种肿重仲盅冢忪锺螽舯踵"};
const u8 PY_mb_zhou  [] = {"舟周州洲诌粥轴肘帚咒皱宙昼骤荮啁妯纣绉胄碡籀繇酎"};
const u8 PY_mb_zhu   [] = {"主住注祝竹珠株蛛朱猪诸诛逐烛煮拄瞩嘱著柱助蛀贮铸筑驻伫竺箸侏属术邾苎茱洙渚潴杼槠橥炷铢疰瘃褚舳翥躅麈丶"};
const u8 PY_mb_zhua  [] = {"抓爪挝"};
const u8 PY_mb_zhuai [] = {"拽转"};
const u8 PY_mb_zhuan [] = {"传专砖转撰赚篆啭馔沌颛"};
const u8 PY_mb_zhuang[] = {"幢桩庄装妆撞壮状奘戆"};
const u8 PY_mb_zhui  [] = {"椎锥追赘坠缀惴骓缒隹"};
const u8 PY_mb_zhun  [] = {"谆准饨肫窀"};
const u8 PY_mb_zhuo  [] = {"着捉拙卓桌灼茁浊酌琢啄倬诼擢浞涿濯焯禚斫镯"};
const u8 PY_mb_zi    [] = {"自子字仔兹咨资姿滋淄孜紫籽滓渍龇姊吱嵫谘茈孳缁梓辎赀恣眦锱秭耔笫粢趑觜訾鲻髭"};
const u8 PY_mb_zong  [] = {"宗综总鬃棕踪纵粽偬枞腙"};
const u8 PY_mb_zou   [] = {"走奏揍邹诹陬鄹驺鲰"};
const u8 PY_mb_zu    [] = {"足组卒族租祖诅阻俎菹镞"};
const u8 PY_mb_zuan  [] = {"钻攥纂缵躜"};
const u8 PY_mb_zui   [] = {"最罪嘴醉蕞觜"};
const u8 PY_mb_zun   [] = {"尊遵樽鳟撙"};
const u8 PY_mb_zuo   [] = {"左佐做作坐座昨撮唑柞阼琢嘬怍胙祚砟酢"};

//拼音索引表
const py_index py_index3[] =
{
    {"", "", (u8 *)PY_mb_space},
    {"2", "a", (u8 *)PY_mb_a},
    {"3", "e", (u8 *)PY_mb_e},
    {"6", "o", (u8 *)PY_mb_o},
    {"24", "ai", (u8 *)PY_mb_ai},
    {"26", "an", (u8 *)PY_mb_an},
    {"26", "ao", (u8 *)PY_mb_ao},
    {"22", "ba", (u8 *)PY_mb_ba},
    {"24", "bi", (u8 *)PY_mb_bi},
    {"26", "bo", (u8 *)PY_mb_bo},
    {"28", "bu", (u8 *)PY_mb_bu},
    {"22", "ca", (u8 *)PY_mb_ca},
    {"23", "ce", (u8 *)PY_mb_ce},
    {"24", "ci", (u8 *)PY_mb_ci},
    {"28", "cu", (u8 *)PY_mb_cu},
    {"32", "da", (u8 *)PY_mb_da},
    {"33", "de", (u8 *)PY_mb_de},
    {"34", "di", (u8 *)PY_mb_di},
    {"38", "du", (u8 *)PY_mb_du},
    {"36", "en", (u8 *)PY_mb_en},
    {"37", "er", (u8 *)PY_mb_er},
    {"32", "fa", (u8 *)PY_mb_fa},
    {"36", "fo", (u8 *)PY_mb_fo},
    {"38", "fu", (u8 *)PY_mb_fu},
    {"42", "ha", (u8 *)PY_mb_ha},
    {"42", "ga", (u8 *)PY_mb_ga},
    {"43", "ge", (u8 *)PY_mb_ge},
    {"43", "he", (u8 *)PY_mb_he},
    {"48", "gu", (u8 *)PY_mb_gu},
    {"48", "hu", (u8 *)PY_mb_hu},
    {"54", "ji", (u8 *)PY_mb_ji},
    {"58", "ju", (u8 *)PY_mb_ju},
    {"52", "ka", (u8 *)PY_mb_ka},
    {"53", "ke", (u8 *)PY_mb_ke},
    {"58", "ku", (u8 *)PY_mb_ku},
    {"52", "la", (u8 *)PY_mb_la},
    {"53", "le", (u8 *)PY_mb_le},
    {"54", "li", (u8 *)PY_mb_li},
    {"58", "lu", (u8 *)PY_mb_lu},
    {"58", "lv", (u8 *)PY_mb_lv},
    {"62", "ma", (u8 *)PY_mb_ma},
    {"63", "me", (u8 *)PY_mb_me},
    {"64", "mi", (u8 *)PY_mb_mi},
    {"66", "mo", (u8 *)PY_mb_mo},
    {"68", "mu", (u8 *)PY_mb_mu},
    {"62", "na", (u8 *)PY_mb_na},
    {"63", "ne", (u8 *)PY_mb_ne},
    {"64", "ni", (u8 *)PY_mb_ni},
    {"68", "nu", (u8 *)PY_mb_nu},
    {"68", "nv", (u8 *)PY_mb_nv},
    {"68", "ou", (u8 *)PY_mb_ou},
    {"72", "pa", (u8 *)PY_mb_pa},
    {"74", "pi", (u8 *)PY_mb_pi},
    {"76", "po", (u8 *)PY_mb_po},
    {"78", "pu", (u8 *)PY_mb_pu},
    {"74", "qi", (u8 *)PY_mb_qi},
    {"78", "qu", (u8 *)PY_mb_qu},
    {"73", "re", (u8 *)PY_mb_re},
    {"74", "ri", (u8 *)PY_mb_ri},
    {"78", "ru", (u8 *)PY_mb_ru},
    {"72", "sa", (u8 *)PY_mb_sa},
    {"73", "se", (u8 *)PY_mb_se},
    {"74", "si", (u8 *)PY_mb_si},
    {"78", "su", (u8 *)PY_mb_su},
    {"82", "ta", (u8 *)PY_mb_ta},
    {"83", "te", (u8 *)PY_mb_te},
    {"84", "ti", (u8 *)PY_mb_ti},
    {"88", "tu", (u8 *)PY_mb_tu},
    {"92", "wa", (u8 *)PY_mb_wa},
    {"96", "wo", (u8 *)PY_mb_wo},
    {"98", "wu", (u8 *)PY_mb_wu},
    {"94", "xi", (u8 *)PY_mb_xi},
    {"98", "xu", (u8 *)PY_mb_xu},
    {"92", "ya", (u8 *)PY_mb_ya},
    {"93", "ye", (u8 *)PY_mb_ye},
    {"94", "yi", (u8 *)PY_mb_yi},
    {"96", "yo", (u8 *)PY_mb_yo},
    {"98", "yu", (u8 *)PY_mb_yu},
    {"92", "za", (u8 *)PY_mb_za},
    {"93", "ze", (u8 *)PY_mb_ze},
    {"94", "zi", (u8 *)PY_mb_zi},
    {"98", "zu", (u8 *)PY_mb_zu},
    {"264", "ang", (u8 *)PY_mb_ang},
    {"224", "bai", (u8 *)PY_mb_bai},
    {"226", "ban", (u8 *)PY_mb_ban},
    {"226", "bao", (u8 *)PY_mb_bao},
    {"234", "bei", (u8 *)PY_mb_bei},
    {"236", "ben", (u8 *)PY_mb_ben},
    {"243", "bie", (u8 *)PY_mb_bie},
    {"246", "bin", (u8 *)PY_mb_bin},
    {"224", "cai", (u8 *)PY_mb_cai},
    {"226", "can", (u8 *)PY_mb_can},
    {"226", "cao", (u8 *)PY_mb_cao},
    {"242", "cha", (u8 *)PY_mb_cha},
    {"243", "che", (u8 *)PY_mb_che},
    {"244", "chi", (u8 *)PY_mb_chi},
    {"248", "chu", (u8 *)PY_mb_chu},
    {"268", "cou", (u8 *)PY_mb_cou},
    {"284", "cui", (u8 *)PY_mb_cui},
    {"286", "cun", (u8 *)PY_mb_cun},
    {"286", "cuo", (u8 *)PY_mb_cuo},
    {"324", "dai", (u8 *)PY_mb_dai},
    {"326", "dan", (u8 *)PY_mb_dan},
    {"326", "dao", (u8 *)PY_mb_dao},
    {"334", "dei", (u8 *)PY_mb_dei},
    {"343", "die", (u8 *)PY_mb_die},
    {"348", "diu", (u8 *)PY_mb_diu},
    {"368", "dou", (u8 *)PY_mb_dou},
    {"384", "dui", (u8 *)PY_mb_dui},
    {"386", "dun", (u8 *)PY_mb_dun},
    {"386", "duo", (u8 *)PY_mb_duo},
    {"326", "fan", (u8 *)PY_mb_fan},
    {"334", "fei", (u8 *)PY_mb_fei},
    {"336", "fen", (u8 *)PY_mb_fen},
    {"368", "fou", (u8 *)PY_mb_fou},
    {"424", "gai", (u8 *)PY_mb_gai},
    {"426", "gan", (u8 *)PY_mb_gan},
    {"426", "gao", (u8 *)PY_mb_gao},
    {"434", "gei", (u8 *)PY_mb_gei},
    {"436", "gen", (u8 *)PY_mb_gan},
    {"468", "gou", (u8 *)PY_mb_gou},
    {"482", "gua", (u8 *)PY_mb_gua},
    {"484", "gui", (u8 *)PY_mb_gui},
    {"486", "gun", (u8 *)PY_mb_gun},
    {"486", "guo", (u8 *)PY_mb_guo},
    {"424", "hai", (u8 *)PY_mb_hai},
    {"426", "han", (u8 *)PY_mb_han},
    {"426", "hao", (u8 *)PY_mb_hao},
    {"434", "hei", (u8 *)PY_mb_hei},
    {"436", "hen", (u8 *)PY_mb_hen},
    {"468", "hou", (u8 *)PY_mb_hou},
    {"482", "hua", (u8 *)PY_mb_hua},
    {"484", "hui", (u8 *)PY_mb_hui},
    {"486", "hun", (u8 *)PY_mb_hun},
    {"486", "huo", (u8 *)PY_mb_huo},
    {"542", "jia", (u8 *)PY_mb_jia},
    {"543", "jie", (u8 *)PY_mb_jie},
    {"546", "jin", (u8 *)PY_mb_jin},
    {"548", "jiu", (u8 *)PY_mb_jiu},
    {"583", "jue", (u8 *)PY_mb_jue},
    {"586", "jun", (u8 *)PY_mb_jun},
    {"524", "kai", (u8 *)PY_mb_kai},
    {"526", "kan", (u8 *)PY_mb_kan},
    {"526", "kao", (u8 *)PY_mb_kao},
    {"536", "ken", (u8 *)PY_mb_ken},
    {"568", "kou", (u8 *)PY_mb_kou},
    {"582", "kua", (u8 *)PY_mb_kua},
    {"584", "kui", (u8 *)PY_mb_kui},
    {"586", "kun", (u8 *)PY_mb_kun},
    {"586", "kuo", (u8 *)PY_mb_kuo},
    {"524", "lai", (u8 *)PY_mb_lai},
    {"526", "lan", (u8 *)PY_mb_lan},
    {"526", "lao", (u8 *)PY_mb_lao},
    {"534", "lei", (u8 *)PY_mb_lei},
    {"543", "lie", (u8 *)PY_mb_lie},
    {"546", "lin", (u8 *)PY_mb_lin},
    {"548", "liu", (u8 *)PY_mb_liu},
    {"568", "lou", (u8 *)PY_mb_lou},
    {"583", "lue", (u8 *)PY_mb_lue},
    {"586", "lun", (u8 *)PY_mb_lun},
    {"586", "luo", (u8 *)PY_mb_luo},
    {"624", "mai", (u8 *)PY_mb_mai},
    {"626", "man", (u8 *)PY_mb_man},
    {"626", "mao", (u8 *)PY_mb_mao},
    {"634", "mei", (u8 *)PY_mb_mei},
    {"636", "men", (u8 *)PY_mb_men},
    {"643", "mie", (u8 *)PY_mb_mie},
    {"646", "min", (u8 *)PY_mb_min},
    {"648", "miu", (u8 *)PY_mb_miu},
    {"668", "mou", (u8 *)PY_mb_mou},
    {"624", "nai", (u8 *)PY_mb_nai},
    {"626", "nan", (u8 *)PY_mb_nan},
    {"626", "nao", (u8 *)PY_mb_nao},
    {"634", "nei", (u8 *)PY_mb_nei},
    {"636", "nen", (u8 *)PY_mb_nen},
    {"643", "nie", (u8 *)PY_mb_nie},
    {"646", "nin", (u8 *)PY_mb_nin},
    {"648", "niu", (u8 *)PY_mb_niu},
    {"683", "nue", (u8 *)PY_mb_nue},
    {"686", "nuo", (u8 *)PY_mb_nuo},
    {"724", "pai", (u8 *)PY_mb_pai},
    {"726", "pan", (u8 *)PY_mb_pan},
    {"726", "pao", (u8 *)PY_mb_pao},
    {"734", "pei", (u8 *)PY_mb_pei},
    {"736", "pen", (u8 *)PY_mb_pen},
    {"743", "pie", (u8 *)PY_mb_pie},
    {"746", "pin", (u8 *)PY_mb_pin},
    {"768", "pou", (u8 *)PY_mb_pou},
    {"742", "qia", (u8 *)PY_mb_qia},
    {"743", "qie", (u8 *)PY_mb_qie},
    {"746", "qin", (u8 *)PY_mb_qin},
    {"748", "qiu", (u8 *)PY_mb_qiu},
    {"783", "que", (u8 *)PY_mb_que},
    {"786", "qun", (u8 *)PY_mb_qun},
    {"726", "ran", (u8 *)PY_mb_ran},
    {"726", "rao", (u8 *)PY_mb_rao},
    {"736", "ren", (u8 *)PY_mb_ren},
    {"768", "rou", (u8 *)PY_mb_rou},
    {"784", "rui", (u8 *)PY_mb_rui},
    {"786", "run", (u8 *)PY_mb_run},
    {"786", "ruo", (u8 *)PY_mb_ruo},
    {"724", "sai", (u8 *)PY_mb_sai},
    {"726", "sao", (u8 *)PY_mb_sao},
    {"726", "san", (u8 *)PY_mb_san},
    {"736", "sen", (u8 *)PY_mb_sen},
    {"742", "sha", (u8 *)PY_mb_sha},
    {"743", "she", (u8 *)PY_mb_she},
    {"744", "shi", (u8 *)PY_mb_shi},
    {"748", "shu", (u8 *)PY_mb_shu},
    {"768", "sou", (u8 *)PY_mb_sou},
    {"784", "sui", (u8 *)PY_mb_sui},
    {"786", "sun", (u8 *)PY_mb_sun},
    {"786", "suo", (u8 *)PY_mb_suo},
    {"824", "tai", (u8 *)PY_mb_tai},
    {"826", "tan", (u8 *)PY_mb_tan},
    {"826", "tao", (u8 *)PY_mb_tao},
    {"843", "tie", (u8 *)PY_mb_tie},
    {"868", "tou", (u8 *)PY_mb_tou},
    {"884", "tui", (u8 *)PY_mb_tui},
    {"886", "tun", (u8 *)PY_mb_tun},
    {"886", "tuo", (u8 *)PY_mb_tuo},
    {"924", "wai", (u8 *)PY_mb_wai},
    {"926", "wan", (u8 *)PY_mb_wan},
    {"934", "wei", (u8 *)PY_mb_wei},
    {"936", "wen", (u8 *)PY_mb_wen},
    {"942", "xia", (u8 *)PY_mb_xia},
    {"943", "xie", (u8 *)PY_mb_xie},
    {"946", "xin", (u8 *)PY_mb_xin},
    {"948", "xiu", (u8 *)PY_mb_xiu},
    {"983", "xue", (u8 *)PY_mb_xue},
    {"986", "xun", (u8 *)PY_mb_xun},
    {"926", "yan", (u8 *)PY_mb_yan},
    {"926", "yao", (u8 *)PY_mb_yao},
    {"946", "yin", (u8 *)PY_mb_yin},
    {"968", "you", (u8 *)PY_mb_you},
    {"983", "yue", (u8 *)PY_mb_yue},
    {"986", "yun", (u8 *)PY_mb_yun},
    {"924", "zai", (u8 *)PY_mb_zai},
    {"926", "zan", (u8 *)PY_mb_zan},
    {"926", "zao", (u8 *)PY_mb_zao},
    {"934", "zei", (u8 *)PY_mb_zei},
    {"936", "zen", (u8 *)PY_mb_zen},
    {"942", "zha", (u8 *)PY_mb_zha},
    {"943", "zhe", (u8 *)PY_mb_zhe},
    {"944", "zhi", (u8 *)PY_mb_zhi},
    {"948", "zhu", (u8 *)PY_mb_zhu},
    {"968", "zou", (u8 *)PY_mb_zou},
    {"984", "zui", (u8 *)PY_mb_zui},
    {"986", "zun", (u8 *)PY_mb_zun},
    {"986", "zuo", (u8 *)PY_mb_zuo},
    {"2264", "bang", (u8 *)PY_mb_bang},
    {"2364", "beng", (u8 *)PY_mb_beng},
    {"2426", "bian", (u8 *)PY_mb_bian},
    {"2426", "biao", (u8 *)PY_mb_biao},
    {"2464", "bing", (u8 *)PY_mb_bing},
    {"2264", "cang", (u8 *)PY_mb_cang},
    {"2364", "ceng", (u8 *)PY_mb_ceng},
    {"2424", "chai", (u8 *)PY_mb_chai},
    {"2426", "chan", (u8 *)PY_mb_chan},
    {"2426", "chao", (u8 *)PY_mb_chao},
    {"2436", "chen", (u8 *)PY_mb_chen},
    {"2468", "chou", (u8 *)PY_mb_chou},
    {"2484", "chuai", (u8 *)PY_mb_chuai},
    {"2484", "chui", (u8 *)PY_mb_chui},
    {"2486", "chun", (u8 *)PY_mb_chun},
    {"2486", "chuo", (u8 *)PY_mb_chuo},
    {"2664", "cong", (u8 *)PY_mb_cong},
    {"2826", "cuan", (u8 *)PY_mb_cuan},
    {"3264", "dang", (u8 *)PY_mb_dang},
    {"3364", "deng", (u8 *)PY_mb_deng},
    {"3426", "dian", (u8 *)PY_mb_dian},
    {"3426", "diao", (u8 *)PY_mb_diao},
    {"3464", "ding", (u8 *)PY_mb_ding},
    {"3664", "dong", (u8 *)PY_mb_dong},
    {"3826", "duan", (u8 *)PY_mb_duan},
    {"3264", "fang", (u8 *)PY_mb_fang},
    {"3364", "feng", (u8 *)PY_mb_feng},
    {"4264", "gang", (u8 *)PY_mb_gang},
    {"4364", "geng", (u8 *)PY_mb_geng},
    {"4664", "gong", (u8 *)PY_mb_gong},
    {"4824", "guai", (u8 *)PY_mb_guai},
    {"4826", "guan", (u8 *)PY_mb_guan},
    {"4264", "hang", (u8 *)PY_mb_hang},
    {"4364", "heng", (u8 *)PY_mb_heng},
    {"4664", "hong", (u8 *)PY_mb_hong},
    {"4823", "huai", (u8 *)PY_mb_huai},
    {"4826", "huan", (u8 *)PY_mb_huan},
    {"5426", "jian", (u8 *)PY_mb_jian},
    {"5426", "jiao", (u8 *)PY_mb_jiao},
    {"5464", "jing", (u8 *)PY_mb_jing},
    {"5826", "juan", (u8 *)PY_mb_juan},
    {"5264", "kang", (u8 *)PY_mb_kang},
    {"5364", "keng", (u8 *)PY_mb_keng},
    {"5664", "kong", (u8 *)PY_mb_kong},
    {"5824", "kuai", (u8 *)PY_mb_kuai},
    {"5826", "kuan", (u8 *)PY_mb_kuan},
    {"5264", "lang", (u8 *)PY_mb_lang},
    {"5366", "leng", (u8 *)PY_mb_leng},
    {"5426", "lian", (u8 *)PY_mb_lian},
    {"5426", "liao", (u8 *)PY_mb_liao},
    {"5464", "ling", (u8 *)PY_mb_ling},
    {"5664", "long", (u8 *)PY_mb_long},
    {"5826", "luan", (u8 *)PY_mb_luan},
    {"6264", "mang", (u8 *)PY_mb_mang},
    {"6364", "meng", (u8 *)PY_mb_meng},
    {"6426", "mian", (u8 *)PY_mb_mian},
    {"6426", "miao", (u8 *)PY_mb_miao},
    {"6464", "ming", (u8 *)PY_mb_ming},
    {"6264", "nang", (u8 *)PY_mb_nang},
    {"6364", "neng", (u8 *)PY_mb_neng},
    {"6426", "nian", (u8 *)PY_mb_nian},
    {"6426", "niao", (u8 *)PY_mb_niao},
    {"6464", "ning", (u8 *)PY_mb_ning},
    {"6664", "nong", (u8 *)PY_mb_nong},
    {"6826", "nuan", (u8 *)PY_mb_nuan},
    {"7264", "pang", (u8 *)PY_mb_pang},
    {"7364", "peng", (u8 *)PY_mb_peng},
    {"7426", "pian", (u8 *)PY_mb_pian},
    {"7426", "piao", (u8 *)PY_mb_piao},
    {"7464", "ping", (u8 *)PY_mb_ping},
    {"7426", "qian", (u8 *)PY_mb_qian},
    {"7426", "qiao", (u8 *)PY_mb_qiao},
    {"7464", "qing", (u8 *)PY_mb_qing},
    {"7826", "quan", (u8 *)PY_mb_quan},
    {"7264", "rang", (u8 *)PY_mb_rang},
    {"7364", "reng", (u8 *)PY_mb_reng},
    {"7664", "rong", (u8 *)PY_mb_rong},
    {"7826", "ruan", (u8 *)PY_mb_ruan},
    {"7264", "sang", (u8 *)PY_mb_sang},
    {"7364", "seng", (u8 *)PY_mb_seng},
    {"7424", "shai", (u8 *)PY_mb_shai},
    {"7426", "shan", (u8 *)PY_mb_shan},
    {"7426", "shao", (u8 *)PY_mb_shao},
    {"7434", "shei", (u8 *)PY_mb_shei},
    {"7436", "shen", (u8 *)PY_mb_shen},
    {"7468", "shou", (u8 *)PY_mb_shou},
    {"7482", "shua", (u8 *)PY_mb_shua},
    {"7484", "shui", (u8 *)PY_mb_shui},
    {"7486", "shun", (u8 *)PY_mb_shun},
    {"7486", "shuo", (u8 *)PY_mb_shuo},
    {"7664", "song", (u8 *)PY_mb_song},
    {"7826", "suan", (u8 *)PY_mb_suan},
    {"8264", "tang", (u8 *)PY_mb_tang},
    {"8364", "teng", (u8 *)PY_mb_teng},
    {"8426", "tian", (u8 *)PY_mb_tian},
    {"8426", "tiao", (u8 *)PY_mb_tiao},
    {"8464", "ting", (u8 *)PY_mb_ting},
    {"8664", "tong", (u8 *)PY_mb_tong},
    {"8826", "tuan", (u8 *)PY_mb_tuan},
    {"9264", "wang", (u8 *)PY_mb_wang},
    {"9364", "weng", (u8 *)PY_mb_weng},
    {"9426", "xian", (u8 *)PY_mb_xian},
    {"9426", "xiao", (u8 *)PY_mb_xiao},
    {"9464", "xing", (u8 *)PY_mb_xing},
    {"9826", "xuan", (u8 *)PY_mb_xuan},
    {"9264", "yang", (u8 *)PY_mb_yang},
    {"9464", "ying", (u8 *)PY_mb_ying},
    {"9664", "yong", (u8 *)PY_mb_yong},
    {"9826", "yuan", (u8 *)PY_mb_yuan},
    {"9264", "zang", (u8 *)PY_mb_zang},
    {"9364", "zeng", (u8 *)PY_mb_zeng},
    {"9424", "zhai", (u8 *)PY_mb_zhai},
    {"9426", "zhan", (u8 *)PY_mb_zhan},
    {"9426", "zhao", (u8 *)PY_mb_zhao},
    {"9436", "zhen", (u8 *)PY_mb_zhen},
    {"9468", "zhou", (u8 *)PY_mb_zhou},
    {"9482", "zhua", (u8 *)PY_mb_zhua},
    {"9484", "zhui", (u8 *)PY_mb_zhui},
    {"9486", "zhun", (u8 *)PY_mb_zhun},
    {"9486", "zhuo", (u8 *)PY_mb_zhuo},
    {"9664", "zong", (u8 *)PY_mb_zong},
    {"9826", "zuan", (u8 *)PY_mb_zuan},
    {"24264", "chang", (u8 *)PY_mb_chang},
    {"24364", "cheng", (u8 *)PY_mb_cheng},
    {"24664", "chong", (u8 *)PY_mb_chong},
    {"24826", "chuan", (u8 *)PY_mb_chuan},
    {"48264", "guang", (u8 *)PY_mb_guang},
    {"48264", "huang", (u8 *)PY_mb_huang},
    {"54264", "jiang", (u8 *)PY_mb_jiang},
    {"54664", "jiong", (u8 *)PY_mb_jiong},
    {"58264", "kuang", (u8 *)PY_mb_kuang},
    {"54264", "liang", (u8 *)PY_mb_liang},
    {"64264", "niang", (u8 *)PY_mb_niang},
    {"74264", "qiang", (u8 *)PY_mb_qiang},
    {"74664", "qiong", (u8 *)PY_mb_qiong},
    {"74264", "shang ", (u8 *)PY_mb_shang},
    {"74364", "sheng", (u8 *)PY_mb_sheng},
    {"74824", "shuai", (u8 *)PY_mb_shuai},
    {"74826", "shuan", (u8 *)PY_mb_shuan},
    {"94264", "xiang", (u8 *)PY_mb_xiang},
    {"94664", "xiong", (u8 *)PY_mb_xiong},
    {"94264", "zhang", (u8 *)PY_mb_zhang},
    {"94364", "zheng", (u8 *)PY_mb_zheng},
    {"94664", "zhong", (u8 *)PY_mb_zhong},
    {"94824", "zhuai", (u8 *)PY_mb_zhuai},
    {"94826", "zhuan", (u8 *)PY_mb_zhuan},
    {"248264", "chuang", (u8 *)PY_mb_chuang},
    {"748264", "shuang", (u8 *)PY_mb_shuang},
    {"948264", "zhuang", (u8 *)PY_mb_zhuang},
};

#endif

