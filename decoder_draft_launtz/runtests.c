#include "tests.h"

int main (void) {

    /* opcode -> assembly tests */
    struct instructionData code;
    
    // console start message
    printf("running opcode --> assembly tests\n...\n");

    test_00(&code); 
    test_01(&code);
    test_02(&code);
    test_03(&code);
    test_04(&code);
    test_05(&code);
    test_06(&code);
    test_07(&code);
    test_08(&code);
    test_09(&code);
    test_0A(&code);
    test_0B(&code);
    test_0C(&code);
    test_0D(&code);
    test_0E(&code);
    test_0F(&code);

    test_10(&code);
    test_11(&code);
    test_12(&code);
    test_13(&code);
    test_14(&code);
    test_15(&code);
    test_16(&code);
    test_17(&code);
    test_18(&code);
    test_19(&code);
    test_1A(&code);
    test_1B(&code);
    test_1C(&code);
    test_1D(&code);
    test_1E(&code);
    test_1F(&code);

    test_20(&code);
    test_21(&code);
    test_22(&code);
    test_23(&code);
    test_24(&code);
    test_25(&code);
    test_26(&code);
    test_27(&code);
    test_28(&code);
    test_29(&code);
    test_2A(&code);
    test_2B(&code);
    test_2C(&code);
    test_2D(&code);
    test_2E(&code);
    test_2F(&code);

    test_30(&code);
    test_31(&code);
    test_32(&code);
    test_33(&code);
    test_34(&code);
    test_35(&code);
    test_36(&code);
    test_37(&code);
    test_38(&code);
    test_39(&code);
    test_3A(&code);
    test_3B(&code);
    test_3C(&code);
    test_3D(&code);
    test_3E(&code);
    test_3F(&code);

    test_40(&code);
    test_41(&code);
    test_42(&code);
    test_43(&code);
    test_44(&code);
    test_45(&code);
    test_46(&code);
    test_47(&code);
    test_48(&code);
    test_49(&code);
    test_4A(&code);
    test_4B(&code);
    test_4C(&code);
    test_4D(&code);
    test_4E(&code);
    test_4F(&code);

    test_50(&code);
    test_51(&code);
    test_52(&code);
    test_53(&code);
    test_54(&code);
    test_55(&code);
    test_56(&code);
    test_57(&code);
    test_58(&code);
    test_59(&code);
    test_5A(&code);
    test_5B(&code);
    test_5C(&code);
    test_5D(&code);
    test_5E(&code);
    test_5F(&code);

    test_60(&code);
    test_61(&code);
    test_62(&code);
    test_63(&code);
    test_64(&code);
    test_65(&code);
    test_66(&code);
    test_67(&code);
    test_68(&code);
    test_69(&code);
    test_6A(&code);
    test_6B(&code);
    test_6C(&code);
    test_6D(&code);
    test_6E(&code);
    test_6F(&code);

    test_70(&code);
    test_71(&code);
    test_72(&code);
    test_73(&code);
    test_74(&code);
    test_75(&code);
    test_76(&code);
    test_77(&code);
    test_78(&code);
    test_79(&code);
    test_7A(&code);
    test_7B(&code);
    test_7C(&code);
    test_7D(&code);
    test_7E(&code);
    test_7F(&code);

    test_80(&code);
    test_81(&code);
    test_82(&code);
    test_83(&code);
    test_84(&code);
    test_85(&code);
    test_86(&code);
    test_87(&code);
    test_88(&code);
    test_89(&code);
    test_8A(&code);
    test_8B(&code);
    test_8C(&code);
    test_8D(&code);
    test_8E(&code);
    test_8F(&code);

    test_90(&code);
    test_91(&code);
    test_92(&code);
    test_93(&code);
    test_94(&code);
    test_95(&code);
    test_96(&code);
    test_97(&code);
    test_98(&code);
    test_99(&code);
    test_9A(&code);
    test_9B(&code);
    test_9C(&code);
    test_9D(&code);
    test_9E(&code);
    test_9F(&code);

    test_A0(&code);
    test_A1(&code);
    test_A2(&code);
    test_A3(&code);
    test_A4(&code);
    test_A5(&code);
    test_A6(&code);
    test_A7(&code);
    test_A8(&code);
    test_A9(&code);
    test_AA(&code);
    test_AB(&code);
    test_AC(&code);
    test_AD(&code);
    test_AE(&code);
    test_AF(&code);

    test_B0(&code);
    test_B1(&code);
    test_B2(&code);
    test_B3(&code);
    test_B4(&code);
    test_B5(&code);
    test_B6(&code);
    test_B7(&code);
    test_B8(&code);
    test_B9(&code);
    test_BA(&code);
    test_BB(&code);
    test_BC(&code);
    test_BD(&code);
    test_BE(&code);
    test_BF(&code);

    test_C0(&code);
    test_C1(&code);
    test_C2(&code);
    test_C3(&code);
    test_C4(&code);
    test_C5(&code);
    test_C6(&code);
    test_C7(&code);
    test_C8(&code);
    test_C9(&code);
    test_CA(&code);
    test_CB(&code);
    test_CC(&code);
    test_CD(&code);
    test_CE(&code);
    test_CF(&code);

    test_D0(&code);
    test_D1(&code);
    test_D2(&code);
    test_D3(&code);
    test_D4(&code);
    test_D5(&code);
    test_D6(&code);
    test_D7(&code);
    test_D8(&code);
    test_D9(&code);
    test_DA(&code);
    test_DB(&code);
    test_DC(&code);
    test_DD(&code);
    test_DE(&code);
    test_DF(&code);

    test_E0(&code);
    test_E1(&code);
    test_E2(&code);
    test_E3(&code);
    test_E4(&code);
    test_E5(&code);
    test_E6(&code);
    test_E7(&code);
    test_E8(&code);
    test_E9(&code);
    test_EA(&code);
    test_EB(&code);
    test_EC(&code);
    test_ED(&code);
    test_EE(&code);
    test_EF(&code);

    test_F0(&code);
    test_F1(&code);
    test_F2(&code);
    test_F3(&code);
    test_F4(&code);
    test_F5(&code);
    test_F6(&code);
    test_F7(&code);
    test_F8(&code);
    test_F9(&code);
    test_FA(&code);
    test_FB(&code);
    test_FC(&code);
    test_FD(&code);
    test_FE(&code);
    test_FF(&code);

    // console success message
    printf("Success! opcode --> assembly tests complete\n");

    /* end opcode -> assembly tests */

    return 0;
}