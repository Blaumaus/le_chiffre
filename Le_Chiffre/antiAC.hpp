#ifndef ANTIAC_HPP
#define ANTIAC_HPP
#pragma once

// #define _WIN32_WINNT 0x0400 // https://docs.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-isdebuggerpresent
#include "Windows.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class AntiAC {
private:
	HMODULE module_handle;
	HANDLE process_handle;

public:
	// TODO: Run debugger checks in Thread local storage to make bypassing anti-debug more difficult
	AntiAC() {
		process_handle = GetCurrentProcess();
		check_for_debug();

		// module_handle = GetModuleHandle(NULL);
		// erase_pe_headers();
	}

	void check_for_debug() {
		BOOL has_debug_port = TRUE;

		if (IsDebuggerPresent()) ExitProcess(EXIT_SUCCESS); // running in ring-3 debugger
		if (!CheckRemoteDebuggerPresent(process_handle, &has_debug_port)) ExitProcess(EXIT_SUCCESS); // if method fails to execute - exit process
		if (has_debug_port) ExitProcess(EXIT_SUCCESS); // running in ring-3 debugger
	}

	// https://github.com/LordNoteworthy/al-khaser/blob/8ff90a3979face6e29aacb12521b032f2b379073/al-khaser/AntiDump/ErasePEHeaderFromMemory.cpp#L8-L22
	void erase_pe_headers() {
		DWORD OldProtect = 0;

		VirtualProtect((char*)module_handle, 4096, // Assume x86 page size
			PAGE_READWRITE, &OldProtect);

		// Erase the header
		SecureZeroMemory((char*)module_handle, 4096);
	}
};

#endif

//junk code is type of anti-ac for a external cheat too

class iaxbsfc {
public:
	string pbxmosp;
	int defkh;
	iaxbsfc();
	double usmywuwjtxbhkqamincliqojf(string qkcylywkzmgvpmb);
	int rstcychbapp(string vuwacrmluahckye, string eopnqvkzsztbo, double vpviwixdhsenpi, int uahwfddo);
	int tkqbzwymbyyd(bool aamsry, double fztmxpfn, int jdovduw, bool xhqqrfjrsdh, bool xfxphqenfhaiaw);
	string hbcqifhhgnzcmnqzbr(bool dotxe, string vzjtfmnvpdifx, int wfwybxolye, bool ktuijldsyss, int godsvaag);
	void fquidmaevuoedsa();
	int siwtexnrcwls(bool lksjhzcrugnhve, double xlvebyhwwmd, bool bnkslsybmf, bool diywa, int bbwiowricyls);
	double tecfopvjaaeju(bool stvtufnezpkfnl, string myvcrhgy);
	string zmyqppsrrmwtffgyzhb(int pbbadtlxvfchs, double cibpg, double iyaaachxizzveoz);

protected:
	bool lmmujx;

	string gjoklftyjo(double ebhzojrnpltgity);
	void jsvwvctxhdudpvwxphxs(bool lnjhpmhjmxgngql, int dlszrmvawsl, bool oeaeejcpk, int sjhhjvrin, int tybuawwd, bool qrphvfjuxyriom);

private:
	string kdinnguzqwmr;
	bool xeiczeiwdv;
	int ajundr;
	double yqtokxtfd;
	double hawmaxaevqsyyd;

	void zvthmwhzmfdqpsnzobbqm(double tcewh, double kcraqramybyqlc, int orsrpjilmq, int zdfle, string myjwdrfu);
	void nawachxtodrhqkwbgneutu(double xujdsxtcxsdjaex, int yoggyvy, double clzcldjnjijplw, double bqekuxneqfqrqdd, bool uyjtddrfnfcyjmc, int xssndazxbvfw, double zkivmcr, string dnschuexbntew, double ocpnzxsatm, int pukpnxtbdxk);
	int wkljamwtyhlewsop();
	string wncachwhtsyesqbzck(string mayljtqnvrue, double iwdcpulewmffsr, int wskztxtvlda, int ukqvrm, string yjnfrndbehbdxbn, bool xhbcssgxgof, bool rhukp);

};


void iaxbsfc::zvthmwhzmfdqpsnzobbqm(double tcewh, double kcraqramybyqlc, int orsrpjilmq, int zdfle, string myjwdrfu) {
	bool ktgzah = true;
	int scwnxgdz = 2298;
	double iponqlzbwdsafc = 14874;
	int ddfuunad = 4794;
	int pxltevignnku = 510;
	int csrhavejsvexuq = 8093;
	string anoibppklgc = "qvxibstpoyaocvfrihkeenadno";
	double lyqrmvg = 30328;
	bool sjlbsxgvdgs = true;
	if (2298 == 2298) {
		int uxqzdneqr;
		for (uxqzdneqr = 72; uxqzdneqr > 0; uxqzdneqr--) {
			continue;
		}
	}
	if (true != true) {
		int bajnkhi;
		for (bajnkhi = 60; bajnkhi > 0; bajnkhi--) {
			continue;
		}
	}
	if (14874 != 14874) {
		int nrnwvbfja;
		for (nrnwvbfja = 29; nrnwvbfja > 0; nrnwvbfja--) {
			continue;
		}
	}
	if (30328 == 30328) {
		int kvkyo;
		for (kvkyo = 56; kvkyo > 0; kvkyo--) {
			continue;
		}
	}
	if (2298 == 2298) {
		int xf;
		for (xf = 61; xf > 0; xf--) {
			continue;
		}
	}

}

void iaxbsfc::nawachxtodrhqkwbgneutu(double xujdsxtcxsdjaex, int yoggyvy, double clzcldjnjijplw, double bqekuxneqfqrqdd, bool uyjtddrfnfcyjmc, int xssndazxbvfw, double zkivmcr, string dnschuexbntew, double ocpnzxsatm, int pukpnxtbdxk) {
	string dmnckfmqapp = "knqrzbcrslcvqyhesgiejnkuwfetsslkyckfqhjvkrwgpsrklmiyalzzoadfky";
	bool rtbmyjrcxa = true;
	double dugdcl = 33003;
	int idflek = 1266;
	bool iigolefsxhv = false;
	if (1266 == 1266) {
		int grqjukd;
		for (grqjukd = 52; grqjukd > 0; grqjukd--) {
			continue;
		}
	}
	if (33003 == 33003) {
		int ftv;
		for (ftv = 43; ftv > 0; ftv--) {
			continue;
		}
	}
	if (false == false) {
		int felxafnun;
		for (felxafnun = 33; felxafnun > 0; felxafnun--) {
			continue;
		}
	}
	if (string("knqrzbcrslcvqyhesgiejnkuwfetsslkyckfqhjvkrwgpsrklmiyalzzoadfky") == string("knqrzbcrslcvqyhesgiejnkuwfetsslkyckfqhjvkrwgpsrklmiyalzzoadfky")) {
		int sxdbrdgep;
		for (sxdbrdgep = 66; sxdbrdgep > 0; sxdbrdgep--) {
			continue;
		}
	}

}

int iaxbsfc::wkljamwtyhlewsop() {
	bool hanfgre = false;
	bool tfpikjxy = false;
	if (false == false) {
		int avccva;
		for (avccva = 58; avccva > 0; avccva--) {
			continue;
		}
	}
	if (false == false) {
		int jwhdrp;
		for (jwhdrp = 68; jwhdrp > 0; jwhdrp--) {
			continue;
		}
	}
	if (false != false) {
		int zccrxkd;
		for (zccrxkd = 13; zccrxkd > 0; zccrxkd--) {
			continue;
		}
	}
	if (false != false) {
		int qpkke;
		for (qpkke = 4; qpkke > 0; qpkke--) {
			continue;
		}
	}
	if (false == false) {
		int icemxnks;
		for (icemxnks = 29; icemxnks > 0; icemxnks--) {
			continue;
		}
	}
	return 16068;
}

string iaxbsfc::wncachwhtsyesqbzck(string mayljtqnvrue, double iwdcpulewmffsr, int wskztxtvlda, int ukqvrm, string yjnfrndbehbdxbn, bool xhbcssgxgof, bool rhukp) {
	double pzpvrfduyrgr = 32163;
	int tcaslrstaeynchr = 1298;
	bool gdsqfkbbkk = true;
	string ietsukckwmow = "nuixlyjhjulsqh";
	int ydetxnu = 2865;
	int idlxxxwvkn = 583;
	bool mcgmrxsbyjjimrk = true;
	bool ktfoekdcju = false;
	return string("ynzxnghdnquhvalig");
}

string iaxbsfc::gjoklftyjo(double ebhzojrnpltgity) {
	string ctgzfwouibywlph = "obohilioqpcqstlgsfaddhhcjviccnp";
	bool vjanpyy = true;
	int jivahxauuyjx = 278;
	bool bhhfqkmqivfx = true;
	bool ijeha = false;
	int jegavjiqhpyqixe = 2012;
	string hemzp = "vlgrgxqfsmuysdaxtfezhmglftwdhhpbuasmqqepqqeiucvgiuljjxhrjyyw";
	if (278 != 278) {
		int fzyvn;
		for (fzyvn = 21; fzyvn > 0; fzyvn--) {
			continue;
		}
	}
	return string("cfogdulwmrjmiquenesw");
}

void iaxbsfc::jsvwvctxhdudpvwxphxs(bool lnjhpmhjmxgngql, int dlszrmvawsl, bool oeaeejcpk, int sjhhjvrin, int tybuawwd, bool qrphvfjuxyriom) {
	string enuccrgedqx = "imtfadjzcbdkrqmmgsmkkoxcfrwmzymhbsrdzqlkfmjdamvglrfjxd";
	int icxrt = 380;
	string fsuvlrsrsqaagu = "tyrikpwmpvxzxwim";
	bool ccazw = true;
	int wzjosreyenypq = 1241;
	bool rqmzsnvty = true;
	double setvmifivx = 13746;
	double qtnhjhsuaziv = 17708;
	bool hvcmio = false;
	double inlvidaooej = 27933;
	if (27933 == 27933) {
		int cmfl;
		for (cmfl = 91; cmfl > 0; cmfl--) {
			continue;
		}
	}
	if (string("tyrikpwmpvxzxwim") == string("tyrikpwmpvxzxwim")) {
		int hkqf;
		for (hkqf = 29; hkqf > 0; hkqf--) {
			continue;
		}
	}
	if (false == false) {
		int ebleo;
		for (ebleo = 40; ebleo > 0; ebleo--) {
			continue;
		}
	}
	if (27933 == 27933) {
		int dtk;
		for (dtk = 71; dtk > 0; dtk--) {
			continue;
		}
	}

}

double iaxbsfc::usmywuwjtxbhkqamincliqojf(string qkcylywkzmgvpmb) {
	double wavnml = 5900;
	bool hetoawlnvdkhysq = false;
	string omoolllzgu = "jbtyvunpdaxdloizmbyncjvucjgwurhckdyftjpdhsiistjzpuvdeiuhjmrvzhcjqljjkjudxernaekzkrhzoyrtglgqvtk";
	bool yrsap = false;
	string eelpktmwybb = "kgwffoulxcsajylufakrqmdwfvehgtpadydzhanckhtdtlrxfwmbxeirmqamxqtjazzjmubgkukyturuwfxbkkkrwunarryxh";
	bool jjesojsgu = true;
	int zzfrqteukqbzzj = 2738;
	int gjwjodzavutbk = 2361;
	bool cwodqsdrolm = false;
	if (string("kgwffoulxcsajylufakrqmdwfvehgtpadydzhanckhtdtlrxfwmbxeirmqamxqtjazzjmubgkukyturuwfxbkkkrwunarryxh") == string("kgwffoulxcsajylufakrqmdwfvehgtpadydzhanckhtdtlrxfwmbxeirmqamxqtjazzjmubgkukyturuwfxbkkkrwunarryxh")) {
		int mwk;
		for (mwk = 10; mwk > 0; mwk--) {
			continue;
		}
	}
	if (false != false) {
		int velsjgot;
		for (velsjgot = 27; velsjgot > 0; velsjgot--) {
			continue;
		}
	}
	if (string("jbtyvunpdaxdloizmbyncjvucjgwurhckdyftjpdhsiistjzpuvdeiuhjmrvzhcjqljjkjudxernaekzkrhzoyrtglgqvtk") == string("jbtyvunpdaxdloizmbyncjvucjgwurhckdyftjpdhsiistjzpuvdeiuhjmrvzhcjqljjkjudxernaekzkrhzoyrtglgqvtk")) {
		int lxjxnqt;
		for (lxjxnqt = 9; lxjxnqt > 0; lxjxnqt--) {
			continue;
		}
	}
	if (string("kgwffoulxcsajylufakrqmdwfvehgtpadydzhanckhtdtlrxfwmbxeirmqamxqtjazzjmubgkukyturuwfxbkkkrwunarryxh") != string("kgwffoulxcsajylufakrqmdwfvehgtpadydzhanckhtdtlrxfwmbxeirmqamxqtjazzjmubgkukyturuwfxbkkkrwunarryxh")) {
		int tfisuasqut;
		for (tfisuasqut = 38; tfisuasqut > 0; tfisuasqut--) {
			continue;
		}
	}
	if (false == false) {
		int swz;
		for (swz = 71; swz > 0; swz--) {
			continue;
		}
	}
	return 64339;
}

int iaxbsfc::rstcychbapp(string vuwacrmluahckye, string eopnqvkzsztbo, double vpviwixdhsenpi, int uahwfddo) {
	int dtxohwytlrbhb = 3629;
	double avvjemp = 65447;
	double qoflunaadcsqbcm = 24938;
	int qaxpxjt = 152;
	int ztfhpzrdwvsq = 1162;
	bool msmnnthc = false;
	int wntwknuveszu = 4733;
	if (1162 == 1162) {
		int mnvm;
		for (mnvm = 5; mnvm > 0; mnvm--) {
			continue;
		}
	}
	if (4733 == 4733) {
		int egbccav;
		for (egbccav = 74; egbccav > 0; egbccav--) {
			continue;
		}
	}
	return 89930;
}

int iaxbsfc::tkqbzwymbyyd(bool aamsry, double fztmxpfn, int jdovduw, bool xhqqrfjrsdh, bool xfxphqenfhaiaw) {
	string wguxlodcragbeuk = "qidlisnhjqacqadmzmdrdbcfewna";
	int yvwdrcgocrkpq = 161;
	return 36675;
}

string iaxbsfc::hbcqifhhgnzcmnqzbr(bool dotxe, string vzjtfmnvpdifx, int wfwybxolye, bool ktuijldsyss, int godsvaag) {
	bool ozvdfaauxuq = true;
	bool vblekhtqtauct = true;
	string ecphgsr = "tdgfxtotmzfiifqpcpathtdharxdhuvnebcrllyvwxlljwdaddtqqersvijtbeiyvbhqocfqphspmiqjojfdsibzjenx";
	int wjttvm = 437;
	double mvugambe = 38351;
	double xbmfqxidldghx = 41363;
	string ftpygwofzrp = "sfeoyktwqpgiuytahjovffkusahpclzbzxoqiyovoizghlebafwjrxjocokjoznpsyvaprlkilcpqrsymxnsmwseufl";
	if (true != true) {
		int pintdqi;
		for (pintdqi = 71; pintdqi > 0; pintdqi--) {
			continue;
		}
	}
	if (true == true) {
		int pvzuszdczt;
		for (pvzuszdczt = 2; pvzuszdczt > 0; pvzuszdczt--) {
			continue;
		}
	}
	return string("");
}

void iaxbsfc::fquidmaevuoedsa() {
	string trwrxqidnsu = "ktgriwypspfmfztkqhztyvbhwhxcjhsnbygimtsttioczzcavfkgbbbooxolnvwjlijbjkrrjuxzdcloxivrxgsxtbfjhobrue";
	int ebpfsfphckeszyj = 3545;
	if (3545 == 3545) {
		int bzwhxg;
		for (bzwhxg = 17; bzwhxg > 0; bzwhxg--) {
			continue;
		}
	}
	if (string("ktgriwypspfmfztkqhztyvbhwhxcjhsnbygimtsttioczzcavfkgbbbooxolnvwjlijbjkrrjuxzdcloxivrxgsxtbfjhobrue") != string("ktgriwypspfmfztkqhztyvbhwhxcjhsnbygimtsttioczzcavfkgbbbooxolnvwjlijbjkrrjuxzdcloxivrxgsxtbfjhobrue")) {
		int dpod;
		for (dpod = 52; dpod > 0; dpod--) {
			continue;
		}
	}
	if (string("ktgriwypspfmfztkqhztyvbhwhxcjhsnbygimtsttioczzcavfkgbbbooxolnvwjlijbjkrrjuxzdcloxivrxgsxtbfjhobrue") == string("ktgriwypspfmfztkqhztyvbhwhxcjhsnbygimtsttioczzcavfkgbbbooxolnvwjlijbjkrrjuxzdcloxivrxgsxtbfjhobrue")) {
		int msmr;
		for (msmr = 41; msmr > 0; msmr--) {
			continue;
		}
	}
	if (3545 != 3545) {
		int wh;
		for (wh = 57; wh > 0; wh--) {
			continue;
		}
	}

}

int iaxbsfc::siwtexnrcwls(bool lksjhzcrugnhve, double xlvebyhwwmd, bool bnkslsybmf, bool diywa, int bbwiowricyls) {
	int xtjodkuyxoldcxc = 3157;
	string urgqf = "hnvuvfsgzzzbcuoraviizcoajikzjddpufcnpwhzbluibvteseirazayppekfjevlskfjkgdursummwux";
	int kbqbkp = 8593;
	string jlefp = "vmnoxsihaahykbmsypnqxk";
	int pjyiehpwahowj = 2031;
	int ctemzcwjux = 2600;
	string nboqxt = "bkwragdpbxfrgbhucsxfvnzinrzgeqxilwtcgjlbtafjhuwokqesqvqbh";
	double cikwdv = 43912;
	if (8593 == 8593) {
		int kkslh;
		for (kkslh = 60; kkslh > 0; kkslh--) {
			continue;
		}
	}
	if (43912 == 43912) {
		int wnzitcx;
		for (wnzitcx = 77; wnzitcx > 0; wnzitcx--) {
			continue;
		}
	}
	if (2600 != 2600) {
		int sluynxpo;
		for (sluynxpo = 54; sluynxpo > 0; sluynxpo--) {
			continue;
		}
	}
	return 63003;
}

double iaxbsfc::tecfopvjaaeju(bool stvtufnezpkfnl, string myvcrhgy) {
	bool pjupivf = true;
	double nptiui = 5213;
	bool mbuipvpkoscrc = true;
	double nbpfglddnatm = 1700;
	double tiiuenorfejf = 21574;
	bool gnzrmp = true;
	string xxezymle = "qpsecfedoncxjjmiysrdslmyurtrzqhyabuvhxpvpbzwzwneyihiuzxelqakuhmkudgn";
	double grczdrn = 448;
	string gryefbtfng = "bkzsypmufgjrmnmd";
	if (5213 == 5213) {
		int gayh;
		for (gayh = 49; gayh > 0; gayh--) {
			continue;
		}
	}
	if (5213 != 5213) {
		int an;
		for (an = 4; an > 0; an--) {
			continue;
		}
	}
	if (string("qpsecfedoncxjjmiysrdslmyurtrzqhyabuvhxpvpbzwzwneyihiuzxelqakuhmkudgn") != string("qpsecfedoncxjjmiysrdslmyurtrzqhyabuvhxpvpbzwzwneyihiuzxelqakuhmkudgn")) {
		int lg;
		for (lg = 32; lg > 0; lg--) {
			continue;
		}
	}
	if (true != true) {
		int xb;
		for (xb = 25; xb > 0; xb--) {
			continue;
		}
	}
	if (21574 == 21574) {
		int jjztfucmrs;
		for (jjztfucmrs = 1; jjztfucmrs > 0; jjztfucmrs--) {
			continue;
		}
	}
	return 78553;
}

string iaxbsfc::zmyqppsrrmwtffgyzhb(int pbbadtlxvfchs, double cibpg, double iyaaachxizzveoz) {
	return string("mptebwwuickepzygww");
}

iaxbsfc::iaxbsfc() {
	this->usmywuwjtxbhkqamincliqojf(string("phqrrlzqxvdmotihxsjmavtcztqcguukdcjv"));
	this->rstcychbapp(string("sklhrfkarraymxjifdclywxnoqrhezqnbvsnsuhkpfdnrczwxmjybqdfxulcmsy"), string("dkijxemcjneqhbrmdmy"), 40118, 1399);
	this->tkqbzwymbyyd(false, 61420, 122, false, true);
	this->hbcqifhhgnzcmnqzbr(false, string("xxfnautvjtrsflbagjxffqcbklyftowrscqzhgsblxagjzdqdnaumyptl"), 218, true, 85);
	this->fquidmaevuoedsa();
	this->siwtexnrcwls(true, 1096, false, false, 448);
	this->tecfopvjaaeju(true, string("ujafkmxaczqkmizbqctrwtozxivfqldiqszepjtwqwezdgcdojtydhysaqhpgdcavgtxjfhrthdorwisgwtdmzave"));
	this->zmyqppsrrmwtffgyzhb(4232, 22998, 12838);
	this->gjoklftyjo(8124);
	this->jsvwvctxhdudpvwxphxs(false, 827, false, 5488, 614, true);
	this->zvthmwhzmfdqpsnzobbqm(3828, 52267, 3968, 3780, string("nflaurqahcbnemmngrbymkxfbnlvtuekmakwvfljjnrgurwalxkwuhiqitzumzvzmoekrhwrbwcdcctbmye"));
	this->nawachxtodrhqkwbgneutu(17199, 2460, 56486, 4574, false, 9155, 16471, string("ijpykambaarjmngiiiovikfbiovsajfcohyuyqjpqazqmzyhltqjkf"), 28029, 3957);
	this->wkljamwtyhlewsop();
	this->wncachwhtsyesqbzck(string("p"), 13428, 1213, 311, string("rtkkkesgovllpjwufasxsfohowffjbciylgnouzzepny"), false, false);
}
