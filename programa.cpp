void outer_product(vector<double> row, vector<double> col, vector<vector<double>>& dst) {
    for(unsigned i = 0; i < row.size(); i++) {
        for(unsigned j = 0; j < col.size(); i++) {
            dst[i][j] = row[i] * col[j];
        }
    }
}

//computes row[i] - val for all i;
void subtract(vector<double> row, double val, vector<double>& dst) {
    for(unsigned i = 0; i < row.size(); i++) {
        dst[i] = row[i] - val;
    }
}

//computes m[i][j] + m2[i][j]
void add(vector<vector<double>> m, vector<vector<double>> m2, vector<vector<double>>& dst) {
    for(unsigned i = 0; i < m.size(); i++) {
        for(unsigned j = 0; j < m[i].size(); j++) { 
            dst[i][j] = m[i][j] + m2[i][j];
        }
    }
}

double mean(std::vector<double> &data) {
    double mean = 0.0;

    for(unsigned i=0; (i < data.size());i++) {
        mean += data[i];
    }

    mean /= data.size();
    return mean;
}

void scale(vector<vector<double>> & d, double alpha) {
    for(unsigned i = 0; i < d.size(); i++) {
        for(unsigned j = 0; j < d[i].size(); j++) {
            d[i][j] *= alpha;
        }
    }
}

void compute_covariance_matrix(vector<vector<double>> & d, vector<vector<double>> & dst) {
    for(unsigned i = 0; i < d.size(); i++) {
        double y_bar = mean(d[i]);
        vector<double> d_d_bar(d[i].size());
        subtract(d[i], y_bar, d_d_bar);
        vector<vector<double>> t(d.size());
        outer_product(d_d_bar, d_d_bar, t);
        add(dst, t, dst);
    } 
    scale(dst, 1/(d.size() - 1));
}

void cover(std::vector<std::vector<double> > &d)
{
    double cov = 0.0; 

    for(unsigned i=0; (i < d.size()); i++)
    {
        for(unsigned j=0; (j < d[i].size()); j++)
        {
            cov += d[i][j] * d[j][i] / (d[i].size() - 1);
            std::cout << cov << " ";
        }
        std::cout << std::endl;
    }
}