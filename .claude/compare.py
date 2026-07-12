import os, glob

def get_names(dir_path, ext, exclude=set()):
    names = set()
    for f in glob.glob(os.path.join(dir_path, f'*.{ext}')):
        base = os.path.splitext(os.path.basename(f))[0]
        if base not in exclude:
            names.add(base)
    return names

exclude_c = {'Hello', '加油_站', 'vc140'}
exclude_cpp = {'Hello', 'twoinone', 'CPP竞赛笔记', 'STL笔记', 'jump2'}
exclude_java = {'Hello', 'Byjava'}
exclude_py = {'Hello', '__pycache__'}

c_names = get_names(r'D:\cproject\leetcode\ByC', 'c', exclude_c)
cpp_names = get_names(r'D:\cproject\leetcode\ByCpp', 'cpp', exclude_cpp)
java_names = get_names(r'D:\cproject\leetcode\Byjava', 'java', exclude_java)
py_names = get_names(r'D:\cproject\leetcode\Bypyhton', 'py', exclude_py)

# Add jump2.cpp as JumpGame2
cpp_names.add('JumpGame2')

chinese_to_english = {
    '两数之和': 'TwoSum',
    '两数之和2': 'TwoSum2',
    '买卖股票的最佳时机': 'MaxProfit',
    '买卖股票的最佳时机2': 'MaxProfit2',
    '买_卖股票的最佳时机': 'MaxProfit',
    '買賣股票的最佳時機': 'MaxProfit',
    '二进制求和': 'AddBinary',
    '二分查找': '二分查找',
    '二叉树的层平均值': '二叉树的层平均值',
    '分发糖果': 'Candy',
    '合并两个有序数组': 'Merge',
    '合并两个有序链表': 'MergeTwoLists',
    '同构字符串': 'IsIsomorphic',
    '多数元素': 'MajorityElement',
    '删除有序数组中的重复项': 'removeDuplicates',
    '删除有序数组中的重复项2': 'RemoveDuplicates2',
    '判断子序列': 'IsSubsequence',
    '加油站': 'GasStation',
    '单词规律': 'WordPattern',
    '反转字符串中的单词': 'ReverseWords',
    '文本左右对齐': 'FullJustify',
    '文本左右对其': 'FullJustify',
    '最后一个单词的长度': 'LengthOfLastWord',
    '最长公共前缀': 'LongestCommonPrefix',
    '有效括号': 'IsValid',
    '盛最多水的容器': 'MaxArea',
    '移除元素': 'RemoveElement',
    '罗马数字转换阿拉伯数字': 'RomanToInt',
    '羅馬數字轉換阿拉伯數字': 'RomanToInt',
    '阿拉伯数字转换罗马数字': 'IntToRoman',
    '环形链表': 'HasCycle',
    'Z型变换': 'ZigZagConvert',
    '验证回文串': 'ValidPalindrome',
    '除自身之外数组的乘积': 'ProductExceptSelf',
    '除自身以外数组乘积': 'ProductExceptSelf',
    'H指数': 'HIndex',
    'H指數': 'HIndex',
    '跳跃游戏': 'CanJump',
    '跳跃游戏2': 'JumpGame2',
    '找出字符串第一个匹配项的下标': 'StrStr',
    'O(1)时间插入、删除和获取随机元素': 'RandomizedSet',
    '时间插入、删除和获取随机元素': 'RandomizedSet',
    '接雨水': 'Trap',
    '三数之和': 'ThreeSum',
    '赎金信': 'CanConstruct',
    '二分查找': '二分查找',
    '二叉树的层平均值': '二叉树的层平均值',
}

def normalize(names):
    result = set()
    for n in names:
        if n in chinese_to_english:
            result.add(chinese_to_english[n])
        else:
            result.add(n)
    return result

c_eng = normalize(c_names)
cpp_eng = normalize(cpp_names)
java_eng = normalize(java_names)
py_eng = normalize(py_names)

# Remove duplicate ZigZag (Convert.java is same problem)
java_eng.discard('Convert')

all_problems = sorted(c_eng | cpp_eng | java_eng | py_eng)

print(f'C: {len(c_eng)} unique problems')
print(f'C++: {len(cpp_eng)} unique problems')
print(f'Java: {len(java_eng)} unique problems')
print(f'Python: {len(py_eng)} unique problems')
print(f'Total unique: {len(all_problems)}')
print()

header = f"{'Problem':<25} {'C':>3} {'C++':>3} {'Java':>4} {'Python':>6}"
print(header)
print('-' * len(header))
for p in all_problems:
    c_v = 'Y' if p in c_eng else ''
    cpp_v = 'Y' if p in cpp_eng else ''
    j_v = 'Y' if p in java_eng else ''
    py_v = 'Y' if p in py_eng else ''
    print(f'{p:<25} {c_v:>3} {cpp_v:>3} {j_v:>4} {py_v:>6}')

print()
print("=== 缺少题解的情况 ===")
for p in all_problems:
    missing = []
    if p not in c_eng: missing.append('C')
    if p not in cpp_eng: missing.append('C++')
    if p not in java_eng: missing.append('Java')
    if p not in py_eng: missing.append('Python')
    if missing:
        print(f'{p}: 缺少 {", ".join(missing)}')
