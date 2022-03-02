if g[x2][y2] != s[i]:  #如果不和规定的相同，那么路程为1
                    w = 1
                if dist[x1][y1] > dist[x][y] + w:
                    if w:
                        q.append([x1, y1])
                    else:
                        q.appendleft([x1, y1])