#ifndef _DATATYPE_H__
#define _DATATYPE_H__

#include <QString>
#include <utility>
#include <cmath>

/**
 * @brief The Param struct
 * 用于来回传数据
 */

struct Param {
    QString qstrExpression;
    QString qstrNewExpression;
    QString qstrLastestInputChar;
    QString qstrResult;
    bool bIsResult;
    bool bPage;
    bool bTranglePageLnv;
    bool bTranglePageHyp;
};

const double PI = 3.14159;
const double E  = 2.71828;

/**
 * 所有按钮的名称
 */

static QString DataArray[49] = {
    "Button_lnv",
    "Button_pi",
    "Button_e",
    "Button_c",
    "Button_back",

    "Button_pow2",
    "Button_complement",
    "Button_abs",
    "Button_exp",
    "Button_mod",

    "Button_sqrt",
    "Button_lpart",
    "Button_rpart",
    "Button_factorial",
    "Button_div",

    "Button_mi",
    "Button_7",
    "Button_8",
    "Button_9",
    "Button_mul",

    "Button_10mi",
    "Button_4",
    "Button_5",
    "Button_6",
    "Button_sub",

    "Button_log",
    "Button_1",
    "Button_2",
    "Button_3",
    "Button_add",

    "Button_ln",
    "Button_re",
    "Button_0",
    "Button_point",
    "Button_equal",

    "Button_TrLnv",
    "Button_sin",
    "Button_cos",
    "Button_tan",
    "Button_hyp",
    "Button_sec",
    "Button_csc",
    "Button_cot",

    "Button_abs2",
    "Button_ceil",
    "Button_floor",
    "Button_rand",
    "Button_dms",
    "Button_deg"
};

/**
 * @brief The INPUT_TYPE enum
 * 枚举所有按钮
 */

/// tagEnumInputType
typedef enum InputType
{
    INPUT_TYPE_LNV = 0,
    INPUT_TYPE_PI,
    INPUT_TYPE_E,
    INPUT_TYPE_C,
    INPUT_TYPE_BACK,

    INPUT_TYPE_POW2,
    INPUT_TYPE_COMPLEMENT,
    INPUT_TYPE_ABS,
    INPUT_TYPE_EXP,
    INPUT_TYPE_MOD,

    INPUT_TYPE_SQRT,
    INPUT_TYPE_LPART,
    INPUT_TYPE_RPART,
    INPUT_TYPE_FACTORIAL,
    INPUT_TYPE_DIV,

    INPUT_TYPE_MI,
    INPUT_TYPE_7,
    INPUT_TYPE_8,
    INPUT_TYPE_9,
    INPUT_TYPE_MUL,

    INPUT_TYPE_10MI,
    INPUT_TYPE_4,
    INPUT_TYPE_5,
    INPUT_TYPE_6,
    INPUT_TYPE_SUB,

    INPUT_TYPE_LOG,
    INPUT_TYPE_1,
    INPUT_TYPE_2,
    INPUT_TYPE_3,
    INPUT_TYPE_ADD,

    INPUT_TYPE_LN,
    INPUT_TYPE_RE,
    INPUT_TYPE_0,
    INPUT_TYPE_POINT,
    INPUT_TYPE_EQUAL,

    INPUT_TYPE_TRLNV,
    INPUT_TYPE_SIN,
    INPUT_TYPE_COS,
    INPUT_TYPE_TAN,
    INPUT_TYPE_HYP,
    INPUT_TYPE_SEC,
    INPUT_TYPE_CSC,
    INPUT_TYPE_COT,

    INPUT_TYPE_ABS2,
    INPUT_TYPE_CEIL,
    INPUT_TYPE_FLOOR,
    INPUT_TYPE_RAND,
    INPUT_TYPE_DMS,
    INPUT_TYPE_DEG
}EnumInputType;

typedef enum tagEnumExample
{
    enFirst = -1,
    enSenconde,
    enThird
}EnumExample;

#endif // _PROTOCOL_H__
