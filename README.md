# study
여르공

## 02-01

뭐야 이자식 실패했나

근데 어케 써야하지?

하아 유력한 
#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

struct Process {
    int id;  // 프로세스 번호
    int arrive_time;
    deque<int> cpu_burst;
    deque<int> io_burst;
};

int main() {
    ifstream fin("multi.inp");
    ofstream fout("multi.out");

    int n;
    fin >> n;

    deque<Process> wait;
    int cur_time = 0;
    int cpu_idle_time = 0;
    int max_end_time = 0;

    for (int i = 0; i < n; i++) {
        int arrive_time, cpu_len;
        fin >> arrive_time;

        Process p;
        p.id = i;  // 프로세스 번호 부여
        p.arrive_time = arrive_time;

        while (fin >> cpu_len) {
            if (cpu_len == -1) {
                break;
            }
            p.cpu_burst.push_back(cpu_len);
            int io_len;
            fin >> io_len;
            p.io_burst.push_back(io_len);
        }

        wait.push_back(p);
    }

    while (!wait.empty()) {
        int min_burst_time = 1001;
        int min_burst_idx = -1;

        for (int i = 0; i < wait.size(); i++) {
            if (wait[i].arrive_time <= cur_time && !wait[i].cpu_burst.empty()) {
                int burst_time = wait[i].cpu_burst.front();
                if (burst_time < min_burst_time) {
                    min_burst_time = burst_time;
                    min_burst_idx = i;
                }
            }
        }

        if (min_burst_idx == -1) {
            int next_arrive_time = wait.front().arrive_time;
            if (next_arrive_time > cur_time) {
                cpu_idle_time += next_arrive_time - cur_time;
                cur_time = next_arrive_time;
            }
        } else {
            Process& cur_p = wait[min_burst_idx];
            cur_p.cpu_burst.pop_front();
            int io_time = cur_p.io_burst.front();
            cur_p.io_burst.pop_front();
            cur_time += min_burst_time + io_time;
            if (cur_p.cpu_burst.empty()) {
                max_end_time = max(max_end_time, cur_time);
                wait.erase(wait.begin() + min_burst_idx);
            }
        }
    }

    fout << cpu_idle_time << " " << max_end_time << endl;
    fin.close();
    fout.close();

    return 0;
}

응 아니었고.

#include <iostream>
using namespace std;

int main() {
    double r;
    cout <<"반지름 입력: ";
    cin >> r;
    cout << "원의 넓이: " << 3.141592 * r * r << endl;
    cout << "구의 부피: " << 3.141592 * (4.0/3.0) * r * r << endl;

    return 0;
}


헤헿


#include <stdio.h>

int main() {
    double r;
    printf("반지름 입력: ");
    scanf("%lf", &r);
    printf("원의 넓이: %lf\n", 3.141592*r*r);
    printf("구의 부피: %lf\n", (4.0 / 3.0) * 3.141592 *r*r);

    return 0;
}
