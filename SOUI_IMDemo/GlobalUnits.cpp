#include "StdAfx.h"
#include "GlobalUnits.h"

CGlobalUnits::CGlobalUnits(void)
{
}

CGlobalUnits::~CGlobalUnits(void)
{
}


CGlobalUnits* CGlobalUnits::GetInstance()
{
	static CGlobalUnits _Instance;
	return &_Instance;
}

std::string CGlobalUnits::GenerateUUID()
{
	char szbuf[100];
	GUID guid;
	::CoCreateGuid(&guid);
	sprintf(szbuf,
		"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
		guid.Data1,
		guid.Data2,
		guid.Data3,
		guid.Data4[0], guid.Data4[1],
		guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]);

	std::string strUUID = szbuf;
	return strUUID;
}

void CGlobalUnits::OperateShamDate()
{
	const char* shamAreas[] = {
		"湖南",
		"湖北",
		"广东",
		"广西壮族自治区",
		"河南",
		"河北",
		"山东",
		"山西",
		"北京市",
		"重庆市",
		"天津市",
		"上海市",
		"江苏",
		"江西",
		"黑龙江",
		"浙江",
		"新疆维吾尔自治区",
		"宁夏回族自治区",
		"辽宁",
		"青海",
		"陕西",
		"甘肃",
		"云南",
		"贵州",
		"西藏自治区",
		"四川",
		"内蒙古自治区",
		"台湾",
		"海南",
		"福建",
		"吉林",
		"安徽",
		"香港特别行政区",
		"澳门特别行政区",
	};

	const char* shamNames[] ={
		"张三",
		"李四",
		"王五",
		"赵六",
		"三英战吕布",
		"三打白骨精",
		"西游记",
		"水浒传",
		"三国演义",
		"红楼梦",
		"金瓶梅",
		"真香定律"
	};

	const char* shamGroupNames[] ={
		"你们肯定没我帅",
		"小姐姐快来玩啊",
		"一看就是个瓜皮",
		"你愁啥",
		"瞅你咋地",
		"再瞅一个试试",
		"试试就试试",
		"西陆",
		"南陆",
		"解放台湾",
		"干倒美帝",
		"一个中国"
	};

	//添加联系人的假数据
	{
		for (int i = 0; i < 50; i++)
		{
			std::string strUUID = GenerateUUID();
			int nNameIndex = rand()%11;
			std::string strTempName = shamNames[nNameIndex];

			std::ostringstream os;
			os.str("");
			os<<strTempName<<i;
			std::string strName = os.str();
			int nAreaIndex = rand()%33;
			std::string strArea = shamAreas[nAreaIndex];
			
			m_mapPersonals.insert(std::make_pair(strUUID, 
				PERSONAL_INFO(strUUID, strName, "", strArea, "鬼知道", "鸟随鸾凤腾飞远，人随贤良品自高。")));
		}
	}

	//添加群的假数据
	{
		for (int i = 0; i < 12; i++)
		{
			std::string strUUID = GenerateUUID();
			int nNameIndex = rand()%11;
			std::string strTempName = shamGroupNames[nNameIndex];

			std::ostringstream os;
			os.str("");
			os<<strTempName<<i;
			std::string strName = os.str();

			m_mapGroups.insert(std::make_pair(strUUID, GROUP_INFO(strUUID, strName, "五一四天假")));
		}
	}
}