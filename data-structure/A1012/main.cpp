//
//  main.cpp
//  A1012
//
//  Created by mark on 2021/1/8.
//  Copyright © 2021 xihe. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace::std;

struct Student {
    long id;
    int C;
    int M;
    int E;
    float AVE;
    int rank[4];
    
}stu[2010];

bool cmp_a(Student A, Student B) {
    return A.AVE > B.AVE;
}

bool cmp_c(Student A, Student B) {
    return A.C > B.C;
}

bool cmp_m(Student A, Student B) {
    return A.M > B.M;
}

bool cmp_e(Student A, Student B) {
    return A.E > B.E;
}

int main() {
    int N, M;
    char dict[] = {'A','C','M','E'};
    scanf("%d %d",&N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%ld %d %d %d", &stu[i].id, &stu[i].C, &stu[i].M, &stu[i].E);
        stu[i].AVE = (stu[i].C + stu[i].M + stu[i].E)/3.0;
    }
    //按平均数进行排序
    sort(stu, stu + N, cmp_a);
    //记录排名
    for (int i = 0; i < N; i++) {
        stu[i].rank[0] = i+1;
    }
    //按C进行排序
    sort(stu, stu + N, cmp_c);
    for (int i = 0; i < N; i++) {
        stu[i].rank[1] = i+1;
    }
    //按M进行排序
    sort(stu, stu + N, cmp_m);
    for (int i = 0; i < N; i++) {
        stu[i].rank[2] = i+1;
    }
    //按E进行排序
    sort(stu, stu + N, cmp_e);
    for (int i = 0; i < N; i++) {
        stu[i].rank[3] = i+1;
    }

    for (int i = 0; i < M; i++) {
        long id;
        //查询
        bool flag = false;
        scanf("%ld",&id);
        for (int j = 0; j < N; j++) {
            if (stu[j].id == id) {
                flag = true;
                //开始输出里面的等级排号
                int min = 0;
                for (int k = 1; k < 4; k++) {
                    if (stu[j].rank[min] > stu[j].rank[k])
                        min = k;
                }
                printf("%d %c\n",stu[j].rank[min], dict[min]);
            }
        }
        if (!flag) {
            printf("N/A\n");
        }
    }
    
    
}
