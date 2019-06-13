# Правда ли, что люди моложе 30 лет выживали чаще,
# чем люди старше 60 лет? Каковы доли выживших в
# обеих группах?
multiplot <- function(..., plotlist=NULL, file, cols=1, layout=NULL) {
  library(grid)
  
  # Make a list from the ... arguments and plotlist
  plots <- c(list(...), plotlist)
  
  numPlots = length(plots)
  
  # If layout is NULL, then use 'cols' to determine layout
  if (is.null(layout)) {
    # Make the panel
    # ncol: Number of columns of plots
    # nrow: Number of rows needed, calculated from # of cols
    layout <- matrix(seq(1, cols * ceiling(numPlots/cols)),
                     ncol = cols, nrow = ceiling(numPlots/cols))
  }
  
  if (numPlots==1) {
    print(plots[[1]])
    
  } else {
    # Set up the page
    grid.newpage()
    pushViewport(viewport(layout = grid.layout(nrow(layout), ncol(layout))))
    
    # Make each plot, in the correct location
    for (i in 1:numPlots) {
      # Get the i,j matrix positions of the regions that contain this subplot
      matchidx <- as.data.frame(which(layout == i, arr.ind = TRUE))
      
      print(plots[[i]], vp = viewport(layout.pos.row = matchidx$row,
                                      layout.pos.col = matchidx$col))
    }
  }
}



library("ggplot2")
data <- read.csv("titanic_train.csv")

young <- data[which(data$Age < 30),]
old <- data[which(data$Age > 60),]

youngTable <- table(young$Survived)
oldTable <- table(old$Survived)

tableNames <- c("died", "survived")
rownames(youngTable) <- tableNames
rownames(oldTable) <- tableNames

youngTable
oldTable

#ggplot(young, aes(x=factor(1), fill=Survived))+geom_bar(width=1)+coord_polar("y")
p1 <- ggplot(young, aes(x="", fill=factor(Survived)))+geom_bar(width=1)+coord_polar("y")+labs(fill="survived", title = "<30")
p2 <- ggplot(old, aes(x="", fill=factor(Survived)))+geom_bar(width=1)+coord_polar("y")+labs(fill="survived", title = ">60")

yF <- mean(young$Survived)
oF <- mean(old$Survived)
data <- data.frame(c(yF, oF))
colnames(data) <- "val"

p3 <- ggplot(aes(x=c("<30", ">60"),y=val, fill=data$val), data=data) + geom_col()+labs(fill="survived fraction", title = "survived")
multiplot(p1, p2, p3)




