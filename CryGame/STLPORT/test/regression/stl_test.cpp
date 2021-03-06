// STLport regression testsuite component.
// To compile as a separate example, please #define MAIN.
#define  __DECLARE_GLOBALS_HERE
#define  __PUT_STATIC_DATA_MEMBERS_HERE
#include "stl.h"
#include <iostream>
#include "stl_test.h"

#if !defined (STLPORT) || defined(__STL_USE_NAMESPACES)
using namespace std;
#endif

int main(int argc, char** argv) {
    int iter_count = ( argc>1 ? 10000 : 1);
    for (; iter_count; iter_count--) {
        accum1_test(argc, argv);
        cout.flush();
        accum2_test(argc, argv);
        cout.flush();
        adjdiff0_test(argc, argv);
        cout.flush();
        adjdiff1_test(argc, argv);
        cout.flush();
        adjdiff2_test(argc, argv);
        cout.flush();
        adjfind0_test(argc, argv);
        cout.flush();
        adjfind1_test(argc, argv);
        cout.flush();
        adjfind2_test(argc, argv);
        cout.flush();
        advance_test(argc, argv);
        cout.flush();
        alg1_test(argc, argv);
        cout.flush();
        alg2_test(argc, argv);
        cout.flush();
        alg3_test(argc, argv);
        cout.flush();
        alg4_test(argc, argv);
        cout.flush();
        alg5_test(argc, argv);
        cout.flush();
        bcompos1_test(argc, argv);
        cout.flush();
        bcompos2_test(argc, argv);
        cout.flush();
        bind1st1_test(argc, argv);
        cout.flush();
        bind1st2_test(argc, argv);
        cout.flush();
        bind2nd1_test(argc, argv);
        cout.flush();
        bind2nd2_test(argc, argv);
        cout.flush();
        binsert1_test(argc, argv);
        cout.flush();
        binsert2_test(argc, argv);
        cout.flush();
        binsrch1_test(argc, argv);
        cout.flush();
        binsrch2_test(argc, argv);
        cout.flush();
        bnegate1_test(argc, argv);
        cout.flush();
        bnegate2_test(argc, argv);
        cout.flush();
	bvec1_test(argc, argv);
        cout.flush();
        copy1_test(argc, argv);
        cout.flush();
        copy2_test(argc, argv);
        cout.flush();
        copy3_test(argc, argv);
        cout.flush();
        copy4_test(argc, argv);
        cout.flush();
        copyb_test(argc, argv);
        cout.flush();
        copyb0_test(argc, argv);
        cout.flush();
        count0_test(argc, argv);
        cout.flush();
        count1_test(argc, argv);
        cout.flush();
        countif1_test(argc, argv);
        cout.flush();
        deque1_test(argc, argv);
        cout.flush();
        divides_test(argc, argv);
        cout.flush();
        eqlrnge0_test(argc, argv);
        cout.flush();
        eqlrnge1_test(argc, argv);
        cout.flush();
        eqlrnge2_test(argc, argv);
        cout.flush();
        equal0_test(argc, argv);
        cout.flush();
        equal1_test(argc, argv);
        cout.flush();
        equal2_test(argc, argv);
        cout.flush();
        equalto_test(argc, argv);
        cout.flush();
        fill1_test(argc, argv);
        cout.flush();
        filln1_test(argc, argv);
        cout.flush();
        find0_test(argc, argv);
        cout.flush();
        find1_test(argc, argv);
        cout.flush();
        findif0_test(argc, argv);
        cout.flush();
        findif1_test(argc, argv);
        cout.flush();
        finsert1_test(argc, argv);
        cout.flush();
        finsert2_test(argc, argv);
        cout.flush();
        foreach0_test(argc, argv);
        cout.flush();
        foreach1_test(argc, argv);
        cout.flush();
        func1_test(argc, argv);
        cout.flush();
        func2_test(argc, argv);
        cout.flush();
        func3_test(argc, argv);
        cout.flush();
        gener1_test(argc, argv);
        cout.flush();
        gener2_test(argc, argv);
        cout.flush();
        genern1_test(argc, argv);
        cout.flush();
        genern2_test(argc, argv);
        cout.flush();
        greateq_test(argc, argv);
        cout.flush();
        greater_test(argc, argv);
        cout.flush();
        incl0_test(argc, argv);
        cout.flush();
        incl1_test(argc, argv);
        cout.flush();
        incl2_test(argc, argv);
        cout.flush();
        inplmrg1_test(argc, argv);
        cout.flush();
        inplmrg2_test(argc, argv);
        cout.flush();
        inrprod0_test(argc, argv);
        cout.flush();
        inrprod1_test(argc, argv);
        cout.flush();
        inrprod2_test(argc, argv);
        cout.flush();
        insert1_test(argc, argv);
        cout.flush();
        insert2_test(argc, argv);
        cout.flush();
        iota1_test(argc, argv);
        cout.flush();
        istmit1_test(argc, argv);
        cout.flush();
        iter1_test(argc, argv);
        cout.flush();
        iter2_test(argc, argv);
        cout.flush();
#if ! (defined(__SUNPRO_CC) && (__SUNPRO_CC<=0x401))
        iter3_test(argc, argv);
        cout.flush();
#endif
        iter4_test(argc, argv);
        cout.flush();
        iterswp0_test(argc, argv);
        cout.flush();
        iterswp1_test(argc, argv);
        cout.flush();
        less_test(argc, argv);
        cout.flush();
        lesseq_test(argc, argv);
        cout.flush();
        lexcmp1_test(argc, argv);
        cout.flush();
        lexcmp2_test(argc, argv);
        cout.flush();
        list1_test(argc, argv);
        cout.flush();
        list2_test(argc, argv);
        cout.flush();
        list3_test(argc, argv);
        cout.flush();
        list4_test(argc, argv);
        cout.flush();
        logicand_test(argc, argv);
        cout.flush();
        logicnot_test(argc, argv);
        cout.flush();
        logicor_test(argc, argv);
        cout.flush();
        lwrbnd1_test(argc, argv);
        cout.flush();
        lwrbnd2_test(argc, argv);
        cout.flush();
        map1_test(argc, argv);
        cout.flush();
        max1_test(argc, argv);
        cout.flush();
        max2_test(argc, argv);
        cout.flush();
        maxelem1_test(argc, argv);
        cout.flush();
        maxelem2_test(argc, argv);
        cout.flush();
        mem_ptr_fun_test(argc, argv);
        cout.flush();
        merge0_test(argc, argv);
        cout.flush();
        merge1_test(argc, argv);
        cout.flush();
        merge2_test(argc, argv);
        cout.flush();
        min1_test(argc, argv);
        cout.flush();
        min2_test(argc, argv);
        cout.flush();
        minelem1_test(argc, argv);
        cout.flush();
        minelem2_test(argc, argv);
        cout.flush();
        minus_test(argc, argv);
        cout.flush();
        mismtch0_test(argc, argv);
        cout.flush();
        mismtch1_test(argc, argv);
        cout.flush();
        mismtch2_test(argc, argv);
        cout.flush();
        mkheap0_test(argc, argv);
        cout.flush();
        mkheap1_test(argc, argv);
        cout.flush();
        mmap1_test(argc, argv);
        cout.flush();
        mmap2_test(argc, argv);
        cout.flush();
        modulus_test(argc, argv);
        cout.flush();
        mset1_test(argc, argv);
        cout.flush();
        mset3_test(argc, argv);
        cout.flush();
        mset4_test(argc, argv);
        cout.flush();
        mset5_test(argc, argv);
        cout.flush();
        negate_test(argc, argv);
        cout.flush();
        nequal_test(argc, argv);
        cout.flush();
        nextprm0_test(argc, argv);
        cout.flush();
        nextprm1_test(argc, argv);
        cout.flush();
        nextprm2_test(argc, argv);
#if ! (defined(__SUNPRO_CC) && (__SUNPRO_CC<=0x410))
        nthelem0_test(argc, argv);
        cout.flush();
        nthelem1_test(argc, argv);
        cout.flush();
        nthelem2_test(argc, argv);
        cout.flush();
#endif
        ostmit_test(argc, argv);
        cout.flush();
        pair0_test(argc, argv);
        cout.flush();
        pair1_test(argc, argv);
        cout.flush();
        pair2_test(argc, argv);
        cout.flush();
        parsrt0_test(argc, argv);
        cout.flush();
        parsrt1_test(argc, argv);
        cout.flush();
        parsrt2_test(argc, argv);
        cout.flush();
        parsrtc0_test(argc, argv);
        cout.flush();
        parsrtc1_test(argc, argv);
        cout.flush();
        parsrtc2_test(argc, argv);
        cout.flush();
        partsrt0_test(argc, argv);
        cout.flush();
        partsum0_test(argc, argv);
        cout.flush();
        partsum1_test(argc, argv);
        cout.flush();
        partsum2_test(argc, argv);
        cout.flush();
        pheap1_test(argc, argv);
        cout.flush();
        pheap2_test(argc, argv);
        cout.flush();
        plus_test(argc, argv);
        cout.flush();
        pqueue1_test(argc, argv);
        cout.flush();
        prevprm0_test(argc, argv);
        cout.flush();
        prevprm1_test(argc, argv);
        cout.flush();
        prevprm2_test(argc, argv);
        cout.flush();
        ptition0_test(argc, argv);
        cout.flush();
        ptition1_test(argc, argv);
        cout.flush();
        ptrbinf1_test(argc, argv);
        cout.flush();
        ptrbinf2_test(argc, argv);
        cout.flush();
        ptrunf1_test(argc, argv);
        cout.flush();
        ptrunf2_test(argc, argv);
        cout.flush();
        queue1_test(argc, argv);
        cout.flush();
        rawiter_test(argc, argv);
        cout.flush();
        remcopy1_test(argc, argv);
        cout.flush();
        remcpif1_test(argc, argv);
        cout.flush();
        remif1_test(argc, argv);
        cout.flush();
        remove1_test(argc, argv);
        cout.flush();
        repcpif1_test(argc, argv);
        cout.flush();
        replace0_test(argc, argv);
        cout.flush();
        replace1_test(argc, argv);
        cout.flush();
        replcpy1_test(argc, argv);
        cout.flush();
        replif1_test(argc, argv);
        cout.flush();
#if ! (defined(__SUNPRO_CC) && (__SUNPRO_CC<0x410))
        revbit1_test(argc, argv);
        cout.flush();
        revbit2_test(argc, argv);
        cout.flush();
#endif
        revcopy1_test(argc, argv);
        cout.flush();
        reverse1_test(argc, argv);
        cout.flush();
#if ! (defined(__SUNPRO_CC) && (__SUNPRO_CC<0x410))
        reviter1_test(argc, argv);
        cout.flush();
        reviter2_test(argc, argv);
        cout.flush();
#endif
        rndshuf0_test(argc, argv);
        cout.flush();
        rndshuf1_test(argc, argv);
        cout.flush();
        rndshuf2_test(argc, argv);
        cout.flush();
        rotate0_test(argc, argv);
        cout.flush();
        rotate1_test(argc, argv);
        cout.flush();
        rotcopy0_test(argc, argv);
        cout.flush();
        rotcopy1_test(argc, argv);
        cout.flush();
        search0_test(argc, argv);
        cout.flush();
        search1_test(argc, argv);
        cout.flush();
        search2_test(argc, argv);
        cout.flush();
        set1_test(argc, argv);
        cout.flush();
        set2_test(argc, argv);
        cout.flush();
        setdiff0_test(argc, argv);
        cout.flush();
        setdiff1_test(argc, argv);
        cout.flush();
        setdiff2_test(argc, argv);
        cout.flush();
        setintr0_test(argc, argv);
        cout.flush();
        setintr1_test(argc, argv);
        cout.flush();
        setintr2_test(argc, argv);
        cout.flush();
        setsymd0_test(argc, argv);
        cout.flush();
        setsymd1_test(argc, argv);
        cout.flush();
        setsymd2_test(argc, argv);
        cout.flush();
        setunon0_test(argc, argv);
        cout.flush();
        setunon1_test(argc, argv);
        cout.flush();
        setunon2_test(argc, argv);
        cout.flush();
        sort1_test(argc, argv);
        cout.flush();
        sort2_test(argc, argv);
        cout.flush();
        stack1_test(argc, argv);
        cout.flush();
        stack2_test(argc, argv);
        cout.flush();
        stblptn0_test(argc, argv);
        cout.flush();
        stblptn1_test(argc, argv);
        cout.flush();
        stblsrt1_test(argc, argv);
        cout.flush();
        stblsrt2_test(argc, argv);
        cout.flush();
        swap1_test(argc, argv);
        cout.flush();
        swprnge1_test(argc, argv);
        cout.flush();
        times_test(argc, argv);
        cout.flush();
        trnsfrm1_test(argc, argv);
        cout.flush();
        trnsfrm2_test(argc, argv);
        cout.flush();
        ucompos1_test(argc, argv);
        cout.flush();
        ucompos2_test(argc, argv);
        cout.flush();
        unegate1_test(argc, argv);
        cout.flush();
        unegate2_test(argc, argv);
        cout.flush();
        uniqcpy1_test(argc, argv);
        cout.flush();
        uniqcpy2_test(argc, argv);
        cout.flush();
        unique1_test(argc, argv);
        cout.flush();
        unique2_test(argc, argv);
        cout.flush();
        uprbnd1_test(argc, argv);
        cout.flush();
        uprbnd2_test(argc, argv);
        cout.flush();
        vec1_test(argc, argv);
        cout.flush();
        vec2_test(argc, argv);
        cout.flush();
        vec3_test(argc, argv);
        cout.flush();
        vec4_test(argc, argv);
        cout.flush();
        vec5_test(argc, argv);
        cout.flush();
        vec6_test(argc, argv);
        cout.flush();
        vec7_test(argc, argv);
        cout.flush();
        vec8_test(argc, argv);
        cout.flush();
        hmap1_test  ( argc, argv);
        cout.flush();
        hmmap1_test  ( argc, argv);
        cout.flush();
        hset2_test  ( argc, argv);
        cout.flush();
        hmset1_test  ( argc, argv);
        cout.flush();
        slist1_test (argc, argv);
        cout.flush();
        string1_test (argc, argv);
        cout.flush();
	bitset1_test (argc, argv); 
        cout.flush();
    }
    return 0;
}
