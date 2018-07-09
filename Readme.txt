1.people student,book assistant, system assistant
2.borrow the book , return the book.
3.change the password
4.update(add or delete the book)
5.clean the list
6.we have a surface to guide the user to do something.
7.csv need!
人类： 需要 存储 ID,PASSWORD 10/30 个空余留给自己借的书
	不同身份权限可以调用的函数
书类：书名，ISBN，价格，作者。评分（最初是初始默认值，每次还书时读者同时进行打分工作），状态（0为可借，1为不可借，此处认为已经借出）。若借出则继续存储借书人的信息（ID）