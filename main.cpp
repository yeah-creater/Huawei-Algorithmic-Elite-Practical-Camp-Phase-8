#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;

int l, n, m, N, M, K = 0;
int latest_over_time = INT_MAX;
vector<int> pre_cost(10010, 0);
vector<tuple<int, int, int, int>> result;
// 定义任务结构体
struct Task {
    int id;
    int size_;
    int output_data_size;
    int earliest_start_time = 0;
    int free_cnt = 0;
    int total_pre_data = 0;
    set<int> affinity_machines;
};

struct CompareTask1 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.earliest_start_time == p2.earliest_start_time) {
        	if (pre_cost[p1.id] == pre_cost[p2.id]){
				if (p1.size_ == p2.size_) {
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
	            }
            	return p1.size_ < p2.size_;
			}
			return pre_cost[p1.id] > pre_cost[p2.id];

        }
        return p1.earliest_start_time > p2.earliest_start_time;
    }
};

struct CompareTask2 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.earliest_start_time == p2.earliest_start_time) {
        	if (pre_cost[p1.id] == pre_cost[p2.id]){
				if (p1.size_ == p2.size_) {
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
	            }
            	return p1.size_ < p2.size_;
			}
			return pre_cost[p1.id] < pre_cost[p2.id];

        }
        return p1.earliest_start_time > p2.earliest_start_time;
    }
};

struct CompareTask3 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.earliest_start_time == p2.earliest_start_time) {
        	if (pre_cost[p1.id] == pre_cost[p2.id]){
				if (p1.size_ == p2.size_) {
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
	            }
            	return p1.size_ > p2.size_;
			}
			return pre_cost[p1.id] > pre_cost[p2.id];

        }
        return p1.earliest_start_time > p2.earliest_start_time;
    }
};

struct CompareTask4 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.earliest_start_time == p2.earliest_start_time) {
        	if (pre_cost[p1.id] == pre_cost[p2.id]){
				if (p1.size_ == p2.size_) {
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
	            }
            	return p1.size_ < p2.size_;
			}
			return pre_cost[p1.id] < pre_cost[p2.id];

        }
        return p1.earliest_start_time > p2.earliest_start_time;
    }
};

struct CompareTask5 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.size_ == p2.size_) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (pre_cost[p1.id] == pre_cost[p2.id]){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return pre_cost[p1.id] < pre_cost[p2.id];
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return p1.size_ < p2.size_;
    }
};

struct CompareTask6 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.size_ == p2.size_) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (pre_cost[p1.id] == pre_cost[p2.id]){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return pre_cost[p1.id] > pre_cost[p2.id];
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return p1.size_ < p2.size_;
    }
};

struct CompareTask7 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.size_ == p2.size_) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (pre_cost[p1.id] == pre_cost[p2.id]){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return pre_cost[p1.id] > pre_cost[p2.id];
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return p1.size_ > p2.size_;
    }
};
struct CompareTask8 {
    bool operator()(const Task& p1, const Task& p2) {
        if (p1.size_ == p2.size_) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (pre_cost[p1.id] == pre_cost[p2.id]){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return pre_cost[p1.id] < pre_cost[p2.id];
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return p1.size_ > p2.size_;
    }
};

struct CompareTask9 {
    bool operator()(const Task& p1, const Task& p2) {
        if (pre_cost[p1.id] ==  pre_cost[p2.id]) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (p1.size_ == p2.size_){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return p1.size_ < p2.size_;
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return pre_cost[p1.id] < pre_cost[p2.id];
    }
};
struct CompareTask10 {
    bool operator()(const Task& p1, const Task& p2) {
        if (pre_cost[p1.id] ==  pre_cost[p2.id]) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (p1.size_ == p2.size_){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return p1.size_ > p2.size_;
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return pre_cost[p1.id] < pre_cost[p2.id];
    }
};
struct CompareTask11 {
    bool operator()(const Task& p1, const Task& p2) {
        if (pre_cost[p1.id] ==  pre_cost[p2.id]) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (p1.size_ == p2.size_){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return p1.size_ < p2.size_;
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return pre_cost[p1.id] > pre_cost[p2.id];
    }
};
struct CompareTask12 {
    bool operator()(const Task& p1, const Task& p2) {
        if (pre_cost[p1.id] ==  pre_cost[p2.id]) {
        	if (p1.earliest_start_time == p2.earliest_start_time) {
        		if (p1.size_ == p2.size_){
	                if (p1.free_cnt == p2.free_cnt){
	                    return p1.affinity_machines.size() < p2.affinity_machines.size();
	                }
	                return p1.free_cnt < p2.free_cnt;
				}
				return p1.size_ < p2.size_;
			}
			return p1.earliest_start_time > p2.earliest_start_time;
		}
		return pre_cost[p1.id] > pre_cost[p2.id];
    }
};




struct PreCompareTask {
    bool operator()(const Task& p1, const Task& p2) {
        return p1.total_pre_data - K * (p1.output_data_size) <
		p2.total_pre_data - K * (p2.output_data_size);
    }
};



// 定义机器结构体
struct Machine {
    int id;
    int power;
    int available_time = 0; // 机器的可用时间初始化为0
};



// 定义磁盘结构体
struct Disk {
    int id;
    int rate;
    int quota;
    int used_quota = 0; // 磁盘的已用配额初始化为0
};

struct CompareDisk {
    bool operator()(const Disk& p1, const Disk& p2) {

        if (p1.rate == p2.rate) {
        	return p1.quota - p1.used_quota > p2.quota - p2.used_quota;
		}
		return p1.rate < p2.rate;

    }
};


// 定义依赖关系结构体
struct Dependency {
    int task_id;
    int dependency_type; // 0表示数据依赖，1表示环境依赖
};

// b / a 上取整
int up(int a, int b) {
	return (a + b - 1 ) / a;
}

void debug(vector<int> &pre_cost, vector<int> &earliest_start_time) {
    for (int i = 1; i <= l; i ++){
        cout << i << "' cost:" << pre_cost[i] << "\n";
    }
    for (int i = 1; i <= l; i ++){
        cout << i << "' e_s_t:" << earliest_start_time[i] << "\n";
    }
}


void working(vector<Task> tasks,
	vector<Machine> machines,
	vector<Disk> disks,
	vector<vector<Dependency>> sons,
    auto ready_tasks_pq,
	auto pre_tasks_pq,
    auto disks_pq_fixed,
    unordered_map<int, int> tasks_disk,
	vector<int> dus,
	int other) {
    vector<tuple<int, int, int, int>> res;
    int over_time = 0;
    vector<int> earliest_start_time(l + 1, 0); // 记录每个任务至少在哪个时间点开始
	vector<int> cpu_earliest_start_time(l + 1, 0); // 记录每个任务至少在哪个时间点开始
	int finish = 0;
    //初始化就绪任务
	for (int i = 1; i <= l; i ++){
		if (dus[i] == 0) {
			dus[i] = -1;
			ready_tasks_pq.push(tasks[i]);
			finish += 1;
		}
		pre_tasks_pq.push(tasks[i]);
	}

    //初始化硬盘固定优先队列
	for (int i = 1;i <= m; i ++){
		disks_pq_fixed.push(disks[i]);
	}

    //动态分配Task为固定的Disk
    while (! pre_tasks_pq.empty()) {
    	auto deal_task = pre_tasks_pq.top();
    	pre_tasks_pq.pop();
        int id = deal_task.id;
        int data = deal_task.output_data_size;
        vector<Disk> disks_tmp;
        while (! disks_pq_fixed.empty()){
            auto deal_disk = disks_pq_fixed.top();
            disks_pq_fixed.pop();
            //剩余额度满足
            if  (deal_disk.quota - deal_disk.used_quota >= data) {
                deal_disk.used_quota += data;
                disks[deal_disk.id].used_quota += data;
                disks_pq_fixed.push(deal_disk);
                tasks_disk[id] = deal_disk.id;
                break;
            }
            disks_tmp.push_back(deal_disk);
		}
        for (auto tt: disks_tmp) {
            disks_pq_fixed.push(tt);
        }
    }

	while (!ready_tasks_pq.empty()){
//        debug(pre_cost, earliest_start_time);

		vector<Task> to_deal_tasks;
		to_deal_tasks.push_back(ready_tasks_pq.top());
		ready_tasks_pq.pop();
		while (! ready_tasks_pq.empty() && finish == l && other) {
			to_deal_tasks.push_back(ready_tasks_pq.top());
			ready_tasks_pq.pop();
		}
		if (finish == l && other) {
			sort(to_deal_tasks.begin(), to_deal_tasks.end(),[&](const Task &t1, const Task &t2) {
				return t1.earliest_start_time > t2.earliest_start_time;
			});
		}
		for (Task deal_task: to_deal_tasks) {
			int id = deal_task.id;
			pair<int, int> earliest_over_time = {0x3f3f3f3f, 0};

			//贪心安排机器, 当前任务完成时间尽可能早
			for (int i = 1; i <= n; i ++) {
				auto deal_machine = machines[i];
				int arrival_time = max({deal_machine.available_time, deal_task.earliest_start_time});
				int over_time = up(deal_machine.power, deal_task.size_) + arrival_time;
				// if (finish != l) {
				// 	over_time = abs(deal_machine.available_time - deal_task.earliest_start_time);
				// }
				//亲和度要满足
				if (over_time < earliest_over_time.first && deal_task.affinity_machines.count(i)){
					earliest_over_time = {up(deal_machine.power, deal_task.size_) + arrival_time, i};
				}
			}

			// 记录执行开始后需要花费的时间(从读取依赖开始)
			int cpu_cost_time = 0, cost_time = 0;
			int machines_idx = earliest_over_time.second;
			auto &deal_machine = machines[machines_idx];
			auto &deal_disk = disks[tasks_disk[id]];
			int arrival_time = max({deal_machine.available_time, deal_task.earliest_start_time});
			deal_machine.available_time = arrival_time;
			res.push_back(make_tuple(id, arrival_time, deal_machine.id, deal_disk.id));
			//cout << id << " " << arrival_time << " " << deal_machine.id << " " <<  deal_disk.id << "\n";
			cost_time += pre_cost[id];
			cpu_cost_time += pre_cost[id];
			cost_time += up(deal_machine.power, deal_task.size_);
			cpu_cost_time += up(deal_machine.power, deal_task.size_);

			cost_time += up(deal_disk.rate, deal_task.output_data_size);

			//使用的mahcine更新参数
			deal_machine.available_time += cost_time;

			over_time = max(over_time, deal_machine.available_time);
			if (over_time >= latest_over_time) {
				return;
			}

			//释放依赖并为其依赖加上读取时间(若必要的话)
			for (auto &son:sons[id]){
				dus[son.task_id] -= 1;
				//数据依赖
				if (son.dependency_type == 0) {
					pre_cost[son.task_id] += up(deal_disk.rate, deal_task.output_data_size);
					earliest_start_time[son.task_id] = max(earliest_start_time[son.task_id], arrival_time + cost_time);
				}
				//环境依赖
				else {
					cpu_earliest_start_time[son.task_id] = max(cpu_earliest_start_time[son.task_id],
					arrival_time + cpu_cost_time);
				}
				if (dus[son.task_id] == 0) {
					tasks[son.task_id].earliest_start_time = max(earliest_start_time[son.task_id],
					cpu_earliest_start_time[son.task_id]);
					ready_tasks_pq.push(tasks[son.task_id]);
					finish += 1;
				}
			}
		}
	}
	if (over_time < latest_over_time) {
		latest_over_time = over_time;
		result = res;
	}
}

void work(vector<Task>& tasks, vector<Machine>& machines, vector<Disk>& disks, vector<pair<int, int>>& data_dependencies, vector<pair<int, int>>& environment_dependencies) {
    vector<vector<Dependency>> sons(l + 1, vector<Dependency>(0)); // 记录每个任务的依赖子节点

    priority_queue<Disk, vector<Disk>, CompareDisk> disks_pq_fixed;	//Disk固定优先队列
    unordered_map<int, int> tasks_disk;// 重要Task的固定Disk 每个测试样例动态分配
	vector<int> dus(l + 1, 0); //记录每个节点的读书来判断是否可以入队
    vector<int> pre_cost_dy(10010, 0);

	for (auto& item:data_dependencies){
    	sons[item.first].push_back({item.second, 0});
    	tasks[item.first].free_cnt += 1;
    	dus[item.second] += 1;
        tasks[item.first].total_pre_data += tasks[item.first].output_data_size;
	}

	for (auto& item:environment_dependencies){
    	sons[item.first].push_back({item.second, 1});
    	tasks[item.first].free_cnt += 1;
    	dus[item.second] += 1;
	}
	priority_queue<Task, vector<Task>, CompareTask1> ready_tasks_pq1;
	priority_queue<Task, vector<Task>, CompareTask2> ready_tasks_pq2;
	priority_queue<Task, vector<Task>, CompareTask3> ready_tasks_pq3;
	priority_queue<Task, vector<Task>, CompareTask4> ready_tasks_pq4;
	priority_queue<Task, vector<Task>, CompareTask5> ready_tasks_pq5;
	priority_queue<Task, vector<Task>, CompareTask6> ready_tasks_pq6;
	priority_queue<Task, vector<Task>, CompareTask7> ready_tasks_pq7;
	priority_queue<Task, vector<Task>, CompareTask8> ready_tasks_pq8;
	priority_queue<Task, vector<Task>, CompareTask9> ready_tasks_pq9;
	priority_queue<Task, vector<Task>, CompareTask10> ready_tasks_pq10;
	priority_queue<Task, vector<Task>, CompareTask11> ready_tasks_pq11;
	priority_queue<Task, vector<Task>, CompareTask12> ready_tasks_pq12;

	vector<int> Ks = {0, -20,-35, -60, 10, 15};
	for(int i = 0; i < Ks.size(); i ++){
		for (int other = 0; other < 1; other ++) {
			K = Ks[i];
			priority_queue<Task, vector<Task>, PreCompareTask> pre_tasks_pq;
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq1, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq2, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq3, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq4, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq5, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq6, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq7, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq8, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq9, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq10, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq11, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			pre_cost = pre_cost_dy;
			working(tasks, machines, disks, sons, ready_tasks_pq12, pre_tasks_pq, disks_pq_fixed, tasks_disk, dus, other);
			
		}
	}


    for (int i = 0; i < l; i ++) {
    	tuple<int, int, int, int> item = result[i];
    	cout << get<0>(item) << " " << get<1>(item) << " " << get<2>(item) << " " << get<3>(item) << "\n";
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> l;
    vector<Task> tasks(l + 1);
    int id;
    // 读取任务信息
    for (int i = 1; i <= l; ++i) {
        int k;
        cin >> id;
        tasks[id].id = id;
        cin >> tasks[id].size_ >> tasks[id].output_data_size >> k;
        for (int j = 0; j < k; ++j) {
        	int x;
        	cin >> x;
            tasks[i].affinity_machines.insert(x);
        }
    }

    // 读取机器信息
    cin >> n;
    vector<Machine> machines(n + 1);

    for (int i = 1; i <= n; ++i) {
    	cin >> id;
    	machines[id].id = id;
        cin >> machines[id].power;
    }

    // 读取磁盘信息
    cin >> m;

    vector<Disk> disks(m + 1);

    for (int i = 1; i <= m; ++i) {
    	cin >> id;
    	disks[id].id = id;
        cin >> disks[i].rate >> disks[i].quota;
    }
    // 读取数据依赖信息
    cin >> N;
    vector<pair<int, int>> data_dependencies(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> data_dependencies[i].first >> data_dependencies[i].second;
    }

    // 读取环境依赖信息
    cin >> M;
    vector<pair<int, int>> environment_dependencies(M + 1);

    for (int i = 1; i <= M; ++i) {
        cin >> environment_dependencies[i].first >> environment_dependencies[i].second;
    }

	work(tasks, machines, disks, data_dependencies, environment_dependencies);

    return 0;
}

