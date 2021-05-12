#pragma once

#define HeightUpdated(x) /*高度更新常规条件*/ \
        ( (x).height == 1 + __max( stature( (x).lc ), stature( (x).rc ) ) )