#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
     vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto &line: cpdomains) {
            auto first_token = line.substr(0, line.find(' '));
            auto domain = line.substr(line.find(' '));
            int count = stoi(first_token);
            m[domain] = count;
            size_t begin = 0;
            while (true) {
                size_t pos = line.find('.',begin);
                if (pos==string::npos)
                    break;
                auto subdomain = line.substr(pos+1);
                m[subdomain] += count;
                begin = pos+1;
            }
        }
        vector<string> ret;
        for (auto &cpi:m) {
            string line = to_string(cpi.second) + " " +cpi.first;
            ret.push_back(line);
            //cout << line << endl;
        }
        return ret;
    }
};

/*
1873 gjf.ca
1873 kse.gjf.ca
8263 cwn.org
2965 gxj.org
7042 btv.com
3090 ycc.yjt.us
8176 ujm.gqs.ca
3377 jkx.network
5016 gqi.co
5016 zwv.gqi.co
8274 ulz.co
7476 yvr.net
7476 cze.yvr.net
2447 ksc.com
9219 tfm.ca
2913 ych.ca
2913 ret.ych.ca
8557 lfn.net
1627 bhp.ca
9523 wyv.cgl.network
3314 hkt.net
3314 ytd.hkt.net
8167 ahm.jre.team
8557 uai.lfn.net
1523 suq.bhp.co
8390 zqk.network
1137 ujs.qzi.co
5705 mqa.wsv.net
7392 uyy.net
4681 lwf.ytn.network
408 tdt.zfz.network
1501 ara.ca
6129 hkt.com
3875 brk.ato.network
6865 thk.net
4296 xtb.jre.us
4521 weh.bfo.us
767 irh.epf.us
6629 vdu.bfo.team
9581 gqi.team
3215 bll.hoh.network
64390 org
5738 lar.bfo.team
9523 cgl.network
7292 ksc.net
654 yls.yjt.co
3528 jyx.arz.us
9103 vbo.org
1225 lmm.ca
9897 lra.uyy.org
654 yaw.lmm.ca
5705 wsv.net
1789 xcf.zqy.ca
7464 fff.co
84 lmm.network
3055 fdy.jkx.com
8342 srp.team
4806 xss.dfa.co
3624 epf.network
8544 bhp.com
8544 xrj.bhp.com
408 zfz.network
1387 hju.gbq.org
5041 cdf.hwu.us
2777 mkw.co
3090 yjt.us
51516 us
2740 xhe.org
9372 hci.jia.network
2531 mce.ser.com
4975 okv.com
8928 arz.org
654 yjt.co
2406 ocf.co
59758 co
68516 net
3055 jkx.com
817 htq.co
4602 buf.team
1781 ksc.co
36170 ca
4439 gtu.us
767 epf.us
4602 weq.buf.team
3609 bhp.team
6920 tlc.dfa.us
6890 bfo.network
6122 srp.org
3322 xhe.team
2531 ser.com
3111 gdw.team
4296 jre.us
5041 hwu.us
58413 com
1781 lbk.ksc.co
9374 jep.ato.co
9374 ato.co
9846 fuw.org
7292 zbl.ksc.net
4521 bfo.us
3624 vmv.epf.network
12367 bfo.team
6920 dfa.us
9172 zfz.net
81314 network
9372 jia.network
7968 gjf.network
2862 coh.sci.net
3449 tfm.us
4806 dfa.co
2862 sci.net
2572 qay.network
3496 ytn.com
59671 team
1387 gbq.org
817 sgp.htq.co
7193 fzx.ca
3528 arz.us
3875 ato.network
3215 hoh.network
2406 hkb.ocf.co
622 cwn.net
1523 bhp.co
7464 jpd.fff.co
2160 hsj.epf.org
2160 epf.org
8167 jre.team
32 ulz.com
1137 qzi.co
4126 ajl.team
9531 hoh.co
7344 czb.com
2471 czb.us
4126 lir.ajl.team
2715 ubt.okv.us
2979 bhp.org
2715 okv.us
1110 kdd.znq.us
1110 znq.us
2777 nak.mkw.co
4198 okv.co
9897 uyy.org
5729 srp.com
6122 nqk.srp.org
4681 ytn.network
3262 mor.ixi.us
3855 yjt.network
7193 xth.fzx.ca
3950 xuf.network
2329 vva.qay.network
7089 ske.yls.com
8176 gqs.ca
9259 bfo.net
7089 yls.com
4198 xfs.okv.co
622 wmt.cwn.net
2444 vks.gxz.team
2444 gxz.team
3262 ixi.us
1789 zqy.ca
5907 zfz.us
9530 omu.network

==
1110 kdd.znq.us
1110 znq.us
1137 qzi.co
1137 ujs.qzi.co
12367 bfo.team
1387 gbq.org
1387 hju.gbq.org
1501 ara.ca
1523 bhp.co
1523 suq.bhp.co
1627 bhp.ca
1781 ksc.co
1781 lbk.ksc.co
1789 xcf.zqy.ca
1789 zqy.ca
1873 gjf.ca
1873 kse.gjf.ca
1879 lmm.ca
2160 epf.org
2160 hsj.epf.org
2329 vva.qay.network
2406 hkb.ocf.co
2406 ocf.co
2444 gxz.team
2444 vks.gxz.team
2447 ksc.com
2471 czb.us
2531 mce.ser.com
2531 ser.com
2572 qay.network
2715 okv.us
2715 ubt.okv.us
2740 xhe.org
2777 mkw.co
2777 nak.mkw.co
2862 coh.sci.net
2862 sci.net
2913 ret.ych.ca
2913 ych.ca
2965 gxj.org
2979 bhp.org
3055 fdy.jkx.com
3055 jkx.com
3090 ycc.yjt.us
3090 yjt.us
3111 gdw.team
32 ulz.com
3215 bll.hoh.network
3215 hoh.network
3262 ixi.us
3262 mor.ixi.us
3314 hkt.net
3314 ytd.hkt.net
3322 xhe.team
3377 jkx.network
3449 tfm.us
3496 ytn.com
3528 arz.us
3528 jyx.arz.us
3609 bhp.team
36170 ca
3624 epf.network
3624 vmv.epf.network
3855 yjt.network
3875 ato.network
3875 brk.ato.network
3950 xuf.network
408 tdt.zfz.network
408 zfz.network
4126 ajl.team
4126 lir.ajl.team
4198 okv.co
4198 xfs.okv.co
4296 jre.us
4296 xtb.jre.us
4439 gtu.us
4521 bfo.us
4521 weh.bfo.us
4602 buf.team
4602 weq.buf.team
4681 lwf.ytn.network
4681 ytn.network
4806 dfa.co
4806 xss.dfa.co
4975 okv.com
5016 gqi.co
5016 zwv.gqi.co
5041 cdf.hwu.us
5041 hwu.us
51516 us
5705 mqa.wsv.net
5705 wsv.net
5729 srp.com
5738 lar.bfo.team
58413 com
5907 zfz.us
59671 team
59758 co
6122 nqk.srp.org
6122 srp.org
6129 hkt.com
622 cwn.net
622 wmt.cwn.net
64390 org
654 yaw.lmm.ca
654 yjt.co
654 yls.yjt.co
6629 vdu.bfo.team
68516 net
6865 thk.net
6890 bfo.network
6920 dfa.us
6920 tlc.dfa.us
7042 btv.com
7089 ske.yls.com
7089 yls.com
7193 fzx.ca
7193 xth.fzx.ca
7292 ksc.net
7292 zbl.ksc.net
7344 czb.com
7392 uyy.net
7464 fff.co
7464 jpd.fff.co
7476 cze.yvr.net
7476 yvr.net
767 epf.us
767 irh.epf.us
7968 gjf.network
81314 network
8167 ahm.jre.team
8167 jre.team
817 htq.co
817 sgp.htq.co
8176 gqs.ca
8176 ujm.gqs.ca
8263 cwn.org
8274 ulz.co
8342 srp.team
8390 zqk.network
84 lmm.network
8544 bhp.com
8544 xrj.bhp.com
8557 lfn.net
8557 uai.lfn.net
8928 arz.org
9103 vbo.org
9172 zfz.net
9219 tfm.ca
9259 bfo.net
9372 hci.jia.network
9372 jia.network
9374 ato.co
9374 jep.ato.co
9523 cgl.network
9523 wyv.cgl.network
9530 omu.network
9531 hoh.co
9581 gqi.team
9846 fuw.org
9897 lra.uyy.org
9897 uyy.org
*/