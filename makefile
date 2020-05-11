FRONTEND_DIR=./sources/frontend
BACKEND_DIR=./sources/backend
EXEC_FE=$(FRONTEND_DIR)/structfe.out
EXEC_BE=$(BACKEND_DIR)/structbe.out 

all: $(EXEC_FE) $(EXEC_BE)

$(EXEC_FE):
	@(cd $(FRONTEND_DIR) && $(MAKE))

$(EXEC_BE):
	@(cd $(BACKEND_DIR) && $(MAKE))

.PHONY: $(EXEC_FE) $(EXEC_BE) clean

clean:
	@(cd $(FRONTEND_DIR) && $(MAKE) $@ && cd ../../$(BACKEND_DIR) && $(MAKE) $@)
