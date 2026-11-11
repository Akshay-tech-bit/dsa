
class Solution:
    def generateTrees(self, n: int):
        
        def build(start, end):
            if start > end:
                return [None]

            result = []

            for i in range(start, end + 1):
                
                leftTrees = build(start, i - 1)
                rightTrees = build(i + 1, end)

                for left in leftTrees:
                    for right in rightTrees:
                        
                        root = TreeNode(i)
                        root.left = left
                        root.right = right

                        result.append(root)

            return result

        return build(1, n)

        