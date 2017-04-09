/*
 * [Source]
 * 
 * https://leetcode.com/problems/reverse-words-in-a-string-iii
 *
 * [Problem Description]
 *
 * Given a string, you need to reverse the order of characters in each word 
 * within a sentence while still preserving whitespace and initial word order.
 *
 * Ex:
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 *
 * Note: In the string, each word is separated by single space and 
 * there will not be any extra space in the string.
 *
 * [Companies]
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reverseWords(char* s)
{
  if (strcmp(s,"") == 0) return "";
  char* result = malloc(sizeof(char) * strlen(s));
  char* token = strtok(s, " ");
  int i, j;
  char temp;
  while(1)
  {
    for(i = 0, j = strlen(token)-1; i<j; i++, j--)
    {
      temp = token[i];
      token[i] = token[j];
      token[j] = temp;
    }
    strcat(result, token);
    token = strtok(NULL, " ");
    if (token != NULL) strcat(result, " ");
    else break;
  }
  return result;
}

int
main()
{
  char s[] = "Let's take LeetCode contest";
  char s2[] = "ijgsp)p*tg%epwh^dnk)e *n^tghtuy$gu!z^aev#ap$nr$zffygcvbdpsbink!m&#hu$( yfwuyw*)ys(@y@tdg&flyu)nfnb^aigzug@pqcfcnhc hewb^igr%jaythexidiphb#s$%t fqjwuodscyxnyxsgw*v)kce)fn%*vd#vyvvqpntoa(mgiflkixl#!cnkvjfobvorxkmbkf*^*mu #d@@fv^@oaohlj!&&w&$j$jbi&bb*jwdk!e))xapln$havgqlkarb^t@bznzijj()wj*&#eyb$%z@ra(tayblwu%$qlpa*ua w(xyi^#pn)zopoarlipqnt^^aflc*^jfk!v(jp%dr*z^cxj$#dv )*^wju$uecophtt#vv#u$))&@tjmmlk&$h(ncvqpcdb@k&^(xvo&$abfdqnylgql$ioa!ffr br)u^f%fed&fruvjyzf)*roh*gv)i@$td*ewfmiag!*u$kt%*jbc@vl@&wc% %onv(z%kdzrlqs^rav@r#%bhzbo(ila#%dxsl&nnyn(rgsokf@$bbyn &th%wktye(zggt$bginrh*o%sffgqj&sz@^@!(akbvum mc**qc$$eawup)v#g#qmxv&qwiwgldpe(pf^ue@&iizjpwoup#&&b^zxu%mwv$#ggf)@c@k@ )buuto*)e#i*suw$@v(kisj!dhwv)*uumamprki$@xrh#za!pcd!&qfp)rpjmh#we(@$vb seu@vf^)#fq@b*emhxjlzs)wicu&#!$aem#w&f!sn#axiq cxc*w)zlvf*&ckua*fwvbrtvvon%w*cdsfa#)ikauzpck e&g*i&!sb)p&u(k!uluipfmk*&@hw^x @@xkjqtefropj!gxrs@&l%f$wovom*nm%pw!$@kph#^jhtsmephjm@^ta@ejq&)aq)qc^mhqq#c e!!btd)rc^gl!k^pqgg&(udti^u&m$$@o&egn(oqaql*@&eb&l@vlgvqsfp##irh! kujugio#sovejzmqlf(qownhm^#h!eube!joutsgrn#ah*jj%cx!djcp#ownh)bkdlm(z(mrfqgr*&t*bf#v#b%!$rw gpb^d&)ed%nkf^iqzqtbf%q&lyf*ayv)(jxux%k*gpklqaff)abgs%%wkrhzgp @wqijb@pr*v$%dyjxcggw!b(fxzfrd ak(mg!k*@vxnq)m*!got%@og*bmqy*n)wmj!ly)j!fjyw#lnvvbpv^mbwwuqsv$@m)^ow*frex#&@g^u#f##h*% @z*rsvggttdrb^ahk)$ie&pyw@^!$m@^&p^kgq@@xke*^%cj)!%qv(wwowxnvreydtvneeqje$xg#(%h&ibbqv(aoa)n#i( &na#y#ytoj*h#!tljmeu!(mlggkvvkialgm%$sim$)vgjk^vi%#qziglfmgles( *hij&!$bss&%f&dwbnwhb@f(vu^^buw^@apipqkk$okb(#k)glvs^npaj%rdq%at@(ni#*azjvse wdwall$)!cjvkywm!wsnymj$etwskec($t*^s@wyuaq!ifajnscvcdtmt!zxbp!wbmwi %)ck%sh^mk*rir^ocgscehlwnorknlv*xwpa$a)xy!b eaorih)@m$kgaw jx#fx*e^&^wbsv^)rylh)er#fkynfheygnx&(ug!cdgefyellj@sdvenbxzake!vm(!&lce&pugz%vobq(ym%i#gbpv zgl*y&dm)@mrxenz&zt(ol@bao cnqfkpt*znzvf&$ysgnepasxfdnqdjxv!qbqpolvk^bxh(qyaaxas!toialtk*f@ppwhvstomtv*s!sm&&ok )#ud!@os*gpdjus(tai*kajyfuedszj*f%oki!sjq(ev#d@(s)jdqx*bxxqw)s!yd^nmz m(y&a^bxlfo^u*!wglh@ezoy)*d!ex*u)fednwzdxy%f%a*cdz) jq!jn)!)c#n rd#ann$yr&icgdaa#sd)sgvwdo**jznp^ukd^qew*#)#dr!*c)wbxah*^wew&& i(k!hgbcm)gf*efvz&d$py)rxeh)%p#rmqmlfo&x^arcshsuak#@e&p!&k uennq(%*dqar %tw)hrxknrznn^roqn%yzlpe!sliefx@k** blxe%@e%mwnp(v*^nw!!cay$&mamrt$o!zq#fwa!yampipghdh(c*mm*e!vf$wqp%^@dmzhh) d**q@blwx@y*i&zjj& h^nn@gwuvqqcxsndrzi*uxzlj(fcw@dd)%%mwy uirajy(zgnwifpju)ar#@xvgekyj%lxsx!uq$#n(aj p^#ey*&$##a^b!npboo!*^jl*oydmg&%lgzr!pbwx)@xl%fuhkcyksrwloslln%cje@y*q*)u^tphfornldd^r()qbn@y* wr&$a$@$eer!ofeevpgsy@gk!plyjdmmaf^@*wb$vpt ^)hwf*ou)h&py^&hm#t&p(z*u$k%o*)jfommxaqh*jkpg@d$xycxv#qmkdr!yc(hztmlh#zz@bh@f%v*xv%o@lqt!d@zug d)les gaxrd*av!$*rn@))uwrf&)ox*tifuc*bziynylns&faiou(fb&bj(#f^doo!h(#v@$xia$&iajimfs&dgyqpn g tskzjekkzlx&(lx#@ucgpwbqsrdk^w^$y%ac b&lgmvrjzz)uqr!y@ faue)cmty#acwfeln)m&^piqd $mgvmh*!cgoaj@@o(^&(ao$(v*m#%zayd#d(n&qn)&rf)g@@(#xi^pyylpl*y%jdb kad%ajmd*n*wiuq*pqsw$kon$%mixtne%a!gpukrxqefa&@mhz^f$#*xcqv t^tayo^lgijbil^gff#zmuf^k@@(vj$ujyl*wju*#^q^g!!el$fu#m)otl)fowh#m&vrxr(l@!@gz)kq)wdymrj ovsqpepg*)((&io %ssdgdhxhh*^&evwr&cm@o*ukhrxkahg%#&a tnp$pkhuh$u$qr!!vb%%q%y!%@&)b(k$rxuw@^!% wvihihcf#^qc!qsck)ctm*f!gsy&ewe@*btjo p#n#wo%ijimkm@nj@u(qyfdyor@g@z&yxh)frko%qtz@cll)%)pnnu nefea^lmg*dzeiic*bati$sg@mcgg*^lrcfhu)dma(hgb!sk@nl$nfl^ngkee*^rqom@)!y&(fyy#me^jrb)rj^^m rss*#royunu*jtwtts#ozqv oa@g!tr#!qdzrjm@ed*#qddlwsubdc*&&()o@zi^enr#x$^qksxqb(p$^ j#$%%g^meh$^u^paslcq^m%hfz%)iz(t @cbonbkdq!!egem$@*!@wv) !iu(*oq(wgqk$eds(h &&sbqtdo$miz^)g)q clwhcozfmbcjqx*h(b@vx@mogf dt^)*rwhwz^g!ia@rrobb%cs&($kjxf#(a$&mvll%$lghwbtzmpi#ndvvc%xlazss@ scj @aj#e&kctovfxin^fzkrw))bcdx!$pcoovi^b&zj#wzfmk@(!bq$%qc^gnzp@%*$!w)u*ires$@mp$fn&(a*jz$&ykh%gj&u wgefgc(ucd$(%)gdgrun(ua^!@djexbs%gt#x!g%#&o$! zu#c$n ^y%oliwlxa%p$^ghvr(wchcbkjvxou@%jkhqgxi#j(q^gp##bs))omkl#^zmuq$%uxoofnklmbe*ic#e %vjqdry&xayu$udhtzeo)ry$pudc$ac$rzw(edki!!s)fnerbmdyyi*^tfxfch!dq)v!c@(cg #%iazqm(%qqpx*#^xdj#($dcbvfiw)jcwyb#g@^ofml@(oxa$^ltzty%@ppeyaeuf*wb*#nmj%xum dykg!nki osito(cz!auv!x%i &l@(nm(uht!m^xcb!orvr%@**d&o)piiwm!yvw*q(tin&#^!ukxb%utbht*nocbkvsjqf (dqua@pj$abgikraxwljht!dv!plp@mxtp*obc(!bt(^t*tu#hlv*u@q@i!o(opi!zizgq(ttkwfgezngs zd(z)bopfysx*)s$ogkku&s&)*!uxn)*)$z$^lg^hlhzb)h@q@(#xbhwhta)$ ks*kukx!cwyxhxt@gopbxy$g&z((iyf*wgaeucwo%rzqdycd)z)bzyjc&r% elaqa#pseuhr@w*fhdj&*m&bmki&pawmawwpfpmdz(lne) fftnpag(ejjzxzw#mz^nj$zsezb!#knvx)q)e!xez$#qyqbqsuibaz$ukzj&vxyignr vjifuvhecebccg)@qfjx#&&^i!v%!qjf(d#gje#d**xql lf$fueifxezms$#btazybsvtyzyi)bmu))xrhmi(zgkaqllaih&f$b(zeykiwgncvaiiff xh#zvqk!yz%cuy(x%u&le@wnf#f@vw(lllw*lcnofos!$upfa@dkx#iq)%g&#)hgdx(f!he b(z^ay#)@jlgav$ll*lc$&shln#yimywj*e((jer^)zu&fvnpka!qlxcfbh& zhdn%#!!rtiyaizy((%rofe)@pexfvsq@%y*q^gh^afo$o*gysnzpfkfjy$qe&g(aqtrwrcaxkpblhrx(^cu^kys^c!r& ^e@jron%dn)bp^g@vkdd!m@ja&jdd#g)^hng*ef)iq@tzxekkm#uimpn ^ahj(ewu)gyzyk&(!n!bktv@w(vpuoxrddqsi!v*$e)rnduy(@k)*t fvw@#bd&$c@o$$w#%xp(yenuc#qx&aaxn^@s$g#%scs)kfpy(xjlfx$fjsx)tamsvsl& fc)zrkop&!nhpopzbpmjk(%%^t^crmhbgwd&zqy oigporcmf(*fxyqunwlm$(lhkakyjbqweva#eihy^zc!y^yvt)m()zclret(n*@&!qh$tm)jkvj$iwvwezt&)nl^okndg$ofhzt n%kk (%$aglrbuaddx)lmr%bz(m)a!yh!npi*qjeq@)t^sputvtmhdkz@u#djg$@pdwyp&izk!w@^oaneztvk!onftd^#@ka&( z@lko&u!z^jec mkkmukuejc*#oanij%dwf!bj^maw@s&rl i#qr#$gcalvq%ozn(v^g%pq%zu$upoj&&^qczm)ra(zkuf$w*(#bxnss!oz)auerph#o)#p*yhgcbn#bze^yjjgby$vs!dee )ixov*jokqm@$tvrjx^&^rtntlgibe@gh)gjsl(hin%k(#m* *zq#gs$u%ol*!kuf!tzmzu)g$y)^#xd@xowtwsphi*&@pzp&&$hdf%yj(rdamdlp& z@tkflgwk&u*)ln(fwljebnjai$@&nxuqkbs!m)gqd)awd^ttdl*!emcttr&!et!po#dk^ccbb%^x$v!ftnc(##mye$*@y nswc&ggh&#jvfu%ppo#nzo&onaif! qef@$!c(tt^m$gka!aso*#@nbqnkpgtqjjjeu%*ap!c(nd!kz&)ic& lflnr*tuwefagh&%putlyoehsj&&mjorwv!^oe)qly#n*nxc$xbn&#e$ cmkokfk$ldugvpzxb^*kceotxom!njovesueggk*m*q$@)s^nn)c ^i#d*tj@p^nj^tmo&v!(a@$*sub()uxl(*h@pav$)fl$khz%(cwrj*k(i^qt*v*e!wz#j)l)wg$sb#ghbyfuw! wu(#ros)yqzechp%fmot*qle)c#ukpfmo&@lrumokid!f@(bbj#vr))$*nrv&xc)n@& k@j&k*&qupd)murnbiiod#uc%u^xp*fjlylctd@bf !vpftese$ydjp#f#mw)lyposl&p*o#l c(sxr!h%*e%z(!^)t@*$xsyxjrc!#@mm)(sirkj&^i^j%$xjmwu)eir*$z%(b$o(%o)pklqlfzvblkv mf#@*@bind$)w!av$oevr$wgtvljqa# n!^ux%bn@%bkyyrf $ypokniczh%!!!kk@^i!p)k)fds&mgqhm%jmtj!ojbkhcpnzdmcnut*$uex!^(r&t%*sfsjvdhinjcpze^wzqm(dr^k%a! b@qu!q!oc!lb@srgfk r$hz@#aerj^lntfxncnsfcocdyky@&!)*gm*&onc*am%a^n#hxf^yc(j!vgsw!tp^iao!fiboh)^lkfzipaknbeb*v w(pze^^%bpt*gkrr^jjw)k*vcb*rjd@qibzzbmf$hyt*#%ejw)xikr&#%zvupgjtd%h@yffnm#sjwnmlfk rt udob(^ix$epwx#uble%gv)ft&foh)gqf(mgm*%buk!mt!rv^xeu!e&zvsa!qe!bwgl#iep^aqhmngomap%#q e*e%k(atpxj@yehd($ccwskwy&s#@oyf&exjgwg)t#zcjoa*njws$^&^@onnjv))bzuw$drpamz!tdzs&@v)ujq i^(sg#pvw*q@^kj!&tdu^lqtfvaw%c#cjystxkwaxbdrw#ek)p%qeuyn*utf!pf!!^o*g@jdjudbtqxo*c^czi^* !smsr #(vvjb%tux!ewskecacuh%fddv!a%gx!xsgo()&l&k$($ibql$cuvju#qx cn()@fakwbxgl*y$wx#$ru!wax^f!eyrwn#whsirwea&hv$l(fqo(h *!*kuolsid$ihmf!s&^js#hvxws#mmnyolv$ ^fu&&)tzvrp$gln@##jd)js)z(x(@(jsrhk#vr^&%c@%jhe#zsfqo*rxxsftb!ko&@ks*%sx@ap !af%gwjnwp)dgdh*^hwv(lsx(u))y$pcdq((yfkbkn&n&xaymeb$nqeukcjk*m(t*ol! m&itdjiqm*$^&%okuc&@mscs%itwq#a!jjrbpvjcsx&jjynv(&xz$#b^j@yvfq((ywqc&%z)p pohm(!ko$#ngs&updj)vtdflzi)u#e((ytlzkb(ne*v@iins$i%duar#o(!piergso^lqsuarfl@zjy(qdx@ujs mgsao#ewee)r!h#^n^)nzmtgo^@ llj%#ocad&#iy#e$coor$n@gafu$ddc@$uwltgvt((^esvli&cwulxa$tfhy*zaouxwx^jl$wppmemr($@eygjbdw^ej$pw)c ajjy#hg(gf*gyj!cqh^s(ing$vvhry@pdx#*ptay!gffqotmhn#byq)jl&jwy!od@mrv)u^s)w*aqdtz^$xcyixl levrf!xnfur&bfoktw#o(stf#r&uzvdaxu^(lxkuipd!dnlidhzwp(pd&dg&&oguxs @ptu&novnvzf^#frerjjh)rvefjx&%a#vedj$rswlzfo%kzytxo*l$%w#^f%(jgxcb&y$ji(vqugobsn!p %cgnqjrkw%#p@)sh$#fblxerhaemhtzbxk%e#%qg%@!hk&ey^kkmyfy^*g $fmxzayqwvpavd)zis^lc!xm!pkxgyus&)wc$gp#gygepdktp&cpref$%!pasp)(tyvbme&d^m%nj#v!!zyg&dftjvjb&hvy@wn^ $hb*r$^dcupqm gzh@djfyajgny)rogbt)ygjx$eob%$mtw)ugdhc hepf^d#*v^lih!q)ujx!k*fevorsx)zb(^af%ep^jzu&oa)^hwke%hs((o%zyaru%lp$y($^xamg@^hg@% spsygdzb^@nh!j*qt%bdi!gaul&b%#k&vwyihqm$v^y#lpn)egxkpl(p#p(vtxv*$q!ahuuiv mm$*u%!d)wt)bgabgv&xvrlwmji)y&!d)(%oas%@fs^!i@a(badtjt)pydmypxvoh)zjyws%^vj)$qmvv $dre( !ja^xjqky%#eo$kae@i%n*&uepfqhxa$#ujiu(zn*&i!n(!kas$%$bwnr&^$jmjzz@@%f(uqekf&vhnpi^ ^*^jb$ait*mtvs!xui^fxpqcvf!pqawbeouwrzbmvo!xwqeu%opqnleqtivyowclpxd!%nh&ehhzmojdy$$aen uu#cgnbbs%rjz#qt^wswrwbafjyzq*czle*on%famied*vdhwe@gme%!oup^rrwsl*%ngigz!x@pmc)zzk^*&x!xkydn (&hnfsqbigk!arcc#h&!)yp)en@e^@ve*^t#lsl$jdzz(vxujzgne &dyyf(yp$wepo^iu&hb*zbwwu@uol%v@odvdowcy)c$ytabf(bqtp &*asxojiwnk%cweq)mqc$wu)b)$@#q&@nm(tqw)edv@tj*$e^#) djp%&afh@$fb!#xm!#&q*(jdm#lbxzuk@qpsiqtv$mk)hiufhukpo%af)ud)&oumd($l)jlqyf%td#aoa quvzq(l&*uywkohvnwgaprux#)#e#&tuk$esr#o^%*z^kjy#ec#r*%ks!)m #eerk#m$xa)u!egbei!tw(uyfehu^$xx**#cf$#wh(px(ypm$e#jlsm* l&fat)nkscrk^jbb%@bu) epzdyde&(tps#o(my&q^dl)utgpujigx&l(@itxmngwjhqtq@*)sxtanspnwspimq)sfjktzwut$u(^#vzlpdy#a!c!osad%sfxl )hi#cl@)#dcfv@wj^q)h*qgjxh$sqtqf#inxda@oh@ti%djurnjqpj k(hjq#^)ecnca^r^*j%ur#@q^gd a@ghscom!zteb*a)ibn&spu*ygjc(wlpk)vf)w!k^!wjvl^pybriyonvq%lz)otg@sitzri) nl$^dyqecm*mfto$p^eq*ghh(uiojxgmzatg najdaongboq^qg^cllt)z*!brmjkaugrnzp%&%lkg&obh!f%l(oq%sbp^*t)saquvzyidyh)wwk( ec(kp^ftgcgwlbraqoru^qfp*rmixo^xyygomd*j(a%ww%x^%nyflf% hcae%^hxgt)b$fanfpbbk@)(op(zvjsdj*)^i!^)ykeermjq k@cx$*xsdgimbkf@pl@t!nqxi&&m!)zq!)e!m(vgu(@rn%k*!dg&c@nrydqh*na^nu!";  
  char* result = reverseWords(s2);
  printf("%s\n", result);
  printf("%d\n", strlen(s2));
}
