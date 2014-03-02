from SpecialBonus import SpecialBonus

class Lobby:
    @classmethod
    def load(cls, para):
        return {'special_bonus': SpecialBonus.load(para)}

