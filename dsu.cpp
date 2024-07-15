class DS {
    vector<int> rank, par, size; 
public: 
    DS(int n) {
        rank.resize(n+1, 0); 
        par.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            par[i] = i; 
            size[i] = 1; 
        }
    }

    int ult_par(int node) {
        if(node == par[node])
            return node; 
        return par[node] = ult_par(par[node]); 
    }

    void runion(int u, int v) {
        int ulp_u = ult_par(u); 
        int ulp_v = ult_par(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            par[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            par[ulp_v] = ulp_u; 
        }
        else {
            par[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void sunion(int u, int v) {
        int ulp_u = ult_par(u); 
        int ulp_v = ult_par(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            par[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
