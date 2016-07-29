//
// Created by BranY on 2016/7/29.
// Contact at wyang@smail.nju.edu.cn
// Copyright (c) 2016 NJU PASA Lab All rights reserved.
//

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class cPrefixSorting {
public :
    cPrefixSorting() {
        m_nCakeCnt = 0;
        m_nMaxSwap = 0;
    }
    ~cPrefixSorting() {
        if (m_CakeArray != NULL) delete m_CakeArray;
        if (m_swapArray != NULL) delete m_swapArray;
        if (m_reverseCakeArray != NULL) delete m_reverseCakeArray;
        if (m_reverseCakeArraySwap != NULL) delete m_reverseCakeArraySwap;
    }

    /**
     * 计算烙饼反转信息
     * @param pCakeArray 存储烙饼索引数组
     * @param nCakeCnt 烙饼个数
     */
    void run(int *pCakeArray, int nCakeCnt) {
        init(pCakeArray, nCakeCnt);
        m_nSearch = 0;
        search(0);
    }

    void output() {
        for (int i = 0; i < m_nMaxSwap; i++)
            cout << m_swapArray[i] << " " ;
        cout << "\n | Search Times | : " << m_nSearch << endl;
        cout << "Total Swap time " << m_nMaxSwap << endl;
    }
private:
    int *m_CakeArray; // 烙饼信息数组
    int m_nCakeCnt;  // 烙饼个数
    int m_nMaxSwap;  // Max swap num

    int *m_swapArray;
    int *m_reverseCakeArray;
    int *m_reverseCakeArraySwap;
    int m_nSearch;
    /**
     * init array
     * @param pCakeArray 存储烙饼索引数组
     * @param nCakeCnt 烙饼个数
     */
    void init(int *pCakeArray, int nCakeCnt) {
        assert(pCakeArray != NULL);
        assert(nCakeCnt > 0);

        m_nCakeCnt = nCakeCnt;
        m_CakeArray = new int[nCakeCnt];
        assert(m_CakeArray != NULL);
        for (int i = 0; i < m_nCakeCnt; i++)
            m_CakeArray[i] = pCakeArray[i];

        m_nMaxSwap = UpperBound(m_nCakeCnt);
        m_swapArray = new int[m_nMaxSwap + 1];
        assert(m_swapArray != NULL);

        m_reverseCakeArray = new int[m_nCakeCnt];
        for (int i = 0; i < m_nCakeCnt; i++)
            m_reverseCakeArray[i] = m_CakeArray[i];
        m_reverseCakeArraySwap = new int[m_nMaxSwap];
    }

    /**
     * 寻找反转上界
     * @param nCakeCnt
     * @return
     */
    int UpperBound(int nCakeCnt) {
        return nCakeCnt * 2;
    }

    /**
     * 寻找反转下界
     * @param nCakeCnt
     * @return
     */
    int LowerBound(int *pCakeArray, int nCakeCnt) {
        int t,ret = 0;
        for (int i = 1; i < nCakeCnt; i++) {
            t = pCakeArray[i] - pCakeArray[i-1];
            if ((t == 1) || (t == -1)) {

            } else
                ret++;
        }
        return ret;
    }

    /**
     * true: sorted
     * false: not sorted
     * @param pCakeArray
     * @param nCakeCnt
     * @return
     */
    bool isSorted(int *pCakeArray, int nCakeCnt) {
        for (int i = 1; i < nCakeCnt; i++)
            if (pCakeArray[i-1] > pCakeArray[i])
                return false;
        return true;
    }

    void reverse(int begin, int end) {
        assert(end > begin);
        int i, j, t;
        for (i = begin, j = end; i < j; i++, j--) {
            t = m_reverseCakeArray[i];
            m_reverseCakeArray[i] = m_reverseCakeArray[j];
            m_reverseCakeArray[j] = t;
        }
    }
    /**
     * 排序主函数
     * @param step
     */
    void search(int step) {
        int i, nEstimate;
        m_nSearch++;
        nEstimate = LowerBound(m_reverseCakeArray, m_nCakeCnt);
        if (step + nEstimate > m_nMaxSwap) return;

        if (isSorted(m_reverseCakeArray, m_nCakeCnt)) {
            if (step < m_nMaxSwap) {
                m_nMaxSwap = step;
                for (i = 0; i < m_nMaxSwap; i++)
                    m_swapArray[i] = m_reverseCakeArraySwap[i];
            }
            return;
        }

        for (i = 1; i < m_nCakeCnt; i++) {
            reverse(0, i);
            m_reverseCakeArraySwap[step] = i;
            search(step + 1);
            reverse(0, i);
        }
    }
};
int main()
{
    cPrefixSorting c;
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> cake(a, a+10);
    c.run(a, 10);
    c.output();
    return 0;
}