local Node = {}
Node.__index = Node

function Node.new(value)
    local self = setmetatable({}, Node)
    self.value = value
    self.left = nil
    self.right = nil
    return self
end

-- Вставка вузла у дерево
function insert(root, value)
    if root == nil then
        return Node.new(value)
    end

    if value < root.value then
        root.left = insert(root.left, value)
    elseif value > root.value then
        root.right = insert(root.right, value)
    end

    return root
end

-- Виведення дерева на екран у вигляді дерева
function printTree(root, level)
    if root == nil then
        return
    end

    level = level or 0
    printTree(root.right, level + 1)
    print(("\t"):rep(level) .. root.value)
    printTree(root.left, level + 1)
end

-- Пошук вузла з заданим значенням
function search(root, value)
    if root == nil or root.value == value then
        return root
    end

    if value < root.value then
        return search(root.left, value)
    else
        return search(root.right, value)
    end
end

-- Знаходження максимального елемента
function findMax(root)
    if root == nil then
        return nil
    end

    while root.right do
        root = root.right
    end

    return root.value
end

-- Функція для запуску програми
function main()
    local root = nil

    -- Введення чисел і вставка їх у дерево
    local numbers = {5, 3, 7, 1, 4, 6, 9}
    for _, number in ipairs(numbers) do
        root = insert(root, number)
    end

    -- Виведення дерева на екран
    print("Дерево:")
    printTree(root)

    -- Пошук заданого числа
    local target = 6
    local targetNode = search(root, target)
    if targetNode then
        print("Число " .. target .. " знайдено у дереві.")
    else
        print("Число " .. target .. " не знайдено у дереві.")
    end

    -- Знаходження максимального елемента
    local max = findMax(root)
    print("Максимальний елемент у дереві: " .. max)
end

-- Виклик функції для запуску програми
main()