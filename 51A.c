#include <stdio.h>
// int solve()
// {
//     int ans = 0;
//     return ans;
// }
int main()
{
    int q; // 10^9
    scanf("%d", &q);
    for (int Case = 1; Case <= q; Case++)
    {
        int n, t, i;
        scanf("%d%d", &n, &t);

        int duration_Of_Video[n + 1];

        for (i = 1; i <= n; i++)
        {
            scanf("%d", &duration_Of_Video[i]);
        }

        int entertain_Of_video[n + 1];

        for (i = 1; i <= n; i++)
        {
            scanf("%d", &entertain_Of_video[i]);
        }

        int ans = -1, maximum_entertainment = 0, skip_time = 0;
        for (i = 1; i <= n; i++)
        {
            int need_time_to_see_this_video = duration_Of_Video[i] + skip_time;

            if (need_time_to_see_this_video <= t)
            {
                if (maximum_entertainment < entertain_Of_video[i])
                {
                    maximum_entertainment = entertain_Of_video[i];
                    ans = i;
                }
            }

            skip_time = skip_time + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}