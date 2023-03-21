dist[v] = max(dist[v], dist[u] + w);
                res = max(res, dist[v]);